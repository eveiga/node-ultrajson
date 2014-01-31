#include <nan.h>

using namespace v8;
using namespace node;

extern "C" {
  #include "ultrajson.h"
}

JSOBJ Object_newString(wchar_t *start, wchar_t *end)
{
}

NAN_METHOD(calculate) {
  JSONObjectDecoder decoder = {
    Object_newString
  };

  JSON_DecodeObject(&decoder, "{}", 4);
}

void init(Handle<Object> target) {
    target->Set(
        NanSymbol("calculate"),
        FunctionTemplate::New(calculate)->GetFunction()
    );
}

NODE_MODULE(ultrajson, init)
