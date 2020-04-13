#ifndef __MVC_OOP_H__
#define __MVC_OOP_H__

#define PUBLIC(type, member)        type member
#define PRIVATE(type, member)       PUBLIC(type, m_##member)

#define CLASS(class_name, members) typedef struct { members } class_name

#define METHOD_NAME(class_name, name) class_name##_##name
#define METHOD_STATIC_DEF(class_name, return_type, name, ...) return_type METHOD_NAME(class_name, name)(__VA_ARGS__)
#define METHOD_DEF(class_name, return_type, name, ...) METHOD_STATIC_DEF(class_name, return_type, name, class_name* $this, __VA_ARGS__)
#define METHOD(class_name, object, name, ...) METHOD_NAME(class_name, name)##(object, __VA_ARGS__)

#define CTOR(class_name, ...) METHOD_DEF(class_name, void, CTOR, __VA_ARGS__)

#define NULLPTR        (void*)0
#define NEW(class_name, obj_name, ...)                                                                   \
								   {                                                                     \
									   class_name* obj_name = (class_name*)malloc( sizeof(class_name) ); \
								       if (obj_name != NULLPTR)                                          \
									   INVOKE_METHOD(class_name, obj_name, CTOR, __VA_ARGS__);           \
								   }
#define DELETE(object) if (object != NULLPTR) { free(object) };

#define USING(class_name, object_name, params, body) NEW(class_name, object_name, params) \
											 { \
												body \
											 } DELETE(object_name);
#endif