#pragma once

#include <queue>
#include <mutex>
#include <condition_variable>

template<typename T>
class ConcurrentQueue {
public:
	void push(T&& item) {
		std::lock_guard lock(mutex);
		queue.push(item);
	}

	void push(const T& item) {
		std::lock_guard lock(mutex);
		queue.push(item);
	}

	T pop_front() {
		std::lock_guard lock(mutex);
		auto item = queue.front();
		queue.pop();
		return item;
	}

	size_t size() {
		std::lock_guard lock(mutex);
		return queue.size();
	}

	bool empty() {
		std::lock_guard lock(mutex);
		return queue.empty();
	}

private:
	std::queue<T> queue;
	std::mutex mutex;
};