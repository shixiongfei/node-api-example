/*
 * node_api_example.c
 *
 * Copyright (c) 2022 Xiongfei Shi
 *
 * Author: Xiongfei Shi <xiongfei.shi(a)icloud.com>
 * License: Apache-2.0
 *
 * https://github.com/shixiongfei/node-api-example
 */

#include <assert.h>
#include <node_api.h>

/*
 * https://nodejs.org/api/n-api.html
 * https://nodejs.github.io/node-addon-examples/
 */

static napi_value hello(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value value;

  status = napi_create_string_utf8(env, "HelloWorld", NAPI_AUTO_LENGTH, &value);
  assert(status == napi_ok);

  return value;
}

static napi_value init(napi_env env, napi_value exports) {
  napi_status status;
  napi_property_descriptor desc[] = {
    {"hello", 0, hello, 0, 0, 0, napi_default, 0}
  };

  status = napi_define_properties(env, exports, 1, desc);
  assert(status == napi_ok);

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)
