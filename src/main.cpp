#include <napi.h>
#include "Wrappers.hpp"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
    return Init(env, exports);
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)
