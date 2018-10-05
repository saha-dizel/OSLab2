#pragma once
#include <mutex>
#include <memory>

#include "point.h"

class safe_ptr {
private:
	std::recursive_mutex mtx_t;
	const std::shared_ptr<Point> ptr;
	std::shared_ptr<std::recursive_mutex> mtx_ptr;

	class auto_lock_t {
	private:
		Point * const ptr;
		std::unique_lock<std::recursive_mutex> lock;
	public:
		auto_lock_t(auto_lock_t&& o) : ptr(std::move(o.ptr)), lock(std::move(o.lock)){}
		auto_lock_t(Point * const _ptr, std::recursive_mutex& _mtx) : ptr(_ptr), lock(_mtx){}
		Point * operator -> (){ return ptr; }
		//we need to build a wall (but actually to learn about this const thing over here, 'cos it's strange)
		const Point * operator -> () const { return ptr; }
	};

	//u need to realise if u need this class, so check it later. Very important
	class auto_lock_obj_t {
	private:
		Point * const ptr;
		std::unique_lock<std::recursive_mutex> lock;
	public:
		auto_lock_obj_t(auto_lock_obj_t&& o) : ptr(std::move(o.ptr)), lock(std::move(o.lock)){}
		auto_lock_obj_t(Point * const _ptr, std::recursive_mutex& _mtx) : ptr(_ptr), lock(_mtx){}

	};
};