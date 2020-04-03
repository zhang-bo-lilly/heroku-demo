
#include "napi.h"

#include "Hello.hpp"

Napi::String runHelloWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 1) {
	Napi::TypeError::New(env, "Wrong number of arguments")
	    .ThrowAsJavaScriptException();
    }

    if (!info[0].IsNumber()) {
	Napi::TypeError::New(env, "Wrong type of argument").
	    ThrowAsJavaScriptException();
    }

    uint32_t val = info[0].As<Napi::Number>().Uint32Value();
    
    runHello(val);
    return Napi::String::New(env,"This message returned from runHelloWrapped");
}

Napi::TypedArrayOf<double> runCalcWrapped(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    if (info.Length() < 2) {
        Napi::TypeError::New(env, "Wrong number of arguments")
            .ThrowAsJavaScriptException();
    }

    if (!info[0].IsTypedArray()) {
        Napi::TypeError::New(env, "Wrong type of in argument").
            ThrowAsJavaScriptException();
    }
    if (!info[1].IsTypedArray()) {
        Napi::TypeError::New(env, "Wrong type of out argument").
            ThrowAsJavaScriptException();
    }

    Napi::TypedArrayOf<double> In = info[0].As<Napi::TypedArrayOf<double> >();
    size_t InLen = In.ElementLength();
    double* pIn = reinterpret_cast<double*>(In.Data());

    Napi::TypedArrayOf<double> Out = info[1].As<Napi::TypedArrayOf<double> >();
    size_t OutLen = Out.ElementLength();
    double* pOut = reinterpret_cast<double*>(Out.Data());
    
    runCalc(pIn,InLen,pOut,OutLen);    

    for(size_t i=0; i<OutLen; ++i,++pOut) {
	Out[i] = *pOut;
    }

    return Out;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("runHello",Napi::Function::New(env, runHelloWrapped));
    exports.Set("runCalc",Napi::Function::New(env, runCalcWrapped));
    return exports;
}
