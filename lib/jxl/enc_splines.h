// Copyright (c) the JPEG XL Project Authors. All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef LIB_JXL_ENC_SPLINES_H_
#define LIB_JXL_ENC_SPLINES_H_

#include <cstddef>

#include "lib/jxl/enc_ans_params.h"
#include "lib/jxl/enc_bit_writer.h"
#include "lib/jxl/image.h"

namespace jxl {

struct AuxOut;

// Only call if splines.HasAny().
void EncodeSplines(const Splines& splines, BitWriter* writer, size_t layer,
                   const HistogramParams& histogram_params, AuxOut* aux_out);

Splines FindSplines(const Image3F& opsin);

}  // namespace jxl

#endif  // LIB_JXL_ENC_SPLINES_H_
