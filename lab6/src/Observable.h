#pragma once

#include <memory>
#include <vector>
#include <set>

template <class T>
class Observer {
public:
	virtual void handle(const T& event) = 0;
};

template <class T>
class Observable {
public:
	void add_observer(std::shared_ptr<Observer<T>> observer) {
		observers.insert(observer);
	}

	void remove_observer(std::shared_ptr<Observer<T>> observer) {
		observers.erase(observer);
	}

protected:
	void notify_observers(const T& event) {
		for (auto& observer : observers) {
			observer->handle(event);
		}
	}

	std::set<std::shared_ptr<Observer<T>>> observers;
};