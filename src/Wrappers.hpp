#ifndef HELLO_WRAPPERS_HPP
#define HELLO_WRAPPERS_HPP

#include "napi.h"

#include "Hello.hpp"

Napi::String runHelloWrapped(const Napi::CallbackInfo& info);
Napi::Object Init(Napi::Env env, Napi::Object exports);


#endif
