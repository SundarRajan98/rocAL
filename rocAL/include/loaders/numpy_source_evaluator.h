/*
Copyright (c) 2019 - 2024 Advanced Micro Devices, Inc. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#pragma once
#include <map>
#include <memory>

#include "loader_module.h"
#include "reader_factory.h"
#include "timing_debug.h"

enum class NumpySourceEvaluatorStatus {
    OK = 0,
    UNSUPPORTED_STORAGE_TYPE,
};

class NumpySourceEvaluator {
   public:
    NumpySourceEvaluatorStatus create(ReaderConfig reader_cfg);
    void find_max_numpy_dimensions();
    std::vector<size_t> max_numpy_dims() { return _max_numpy_dims; }
    RocalTensorDataType get_numpy_dtype() { return _numpy_dtype; }

    std::vector<size_t> _max_numpy_dims;
    RocalTensorDataType _numpy_dtype;
    std::shared_ptr<Reader> _reader;
};
