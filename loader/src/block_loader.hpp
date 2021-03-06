/*
 Copyright 2016 Nervana Systems Inc.
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#pragma once
#include <random>
#include "buffer_in.hpp"

/*
 * A block_loader is something which can load blocks of data into a buffer_in_array
 */

namespace nervana
{
    class block_loader;
}

class nervana::block_loader
{
public:
    virtual void load_block(nervana::buffer_in_array& dest, uint32_t block_num) = 0;
    virtual void prefetch_block(uint32_t block_num);
    virtual uint32_t object_count() = 0;

    uint32_t block_count();
    uint32_t block_size();

protected:
    block_loader(uint32_t block_size);
    uint32_t _block_size;
};
