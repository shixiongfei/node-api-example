/*
 * index.js
 *
 * Copyright (c) 2022 Xiongfei Shi
 *
 * Author: Xiongfei Shi <xiongfei.shi(a)icloud.com>
 * License: Apache-2.0
 *
 * https://github.com/shixiongfei/node-api-example
 */

const binding = require('node-gyp-build')(__dirname)

console.log(binding.hello())
