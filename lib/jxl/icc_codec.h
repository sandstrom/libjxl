// Copyright (c) the JPEG XL Project Authors. All rights reserved.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#ifndef LIB_JXL_ICC_CODEC_H_
#define LIB_JXL_ICC_CODEC_H_

// Compressed representation of ICC profiles.

#include <cstddef>
#include <cstdint>

#include "lib/jxl/base/compiler_specific.h"
#include "lib/jxl/base/padded_bytes.h"
#include "lib/jxl/base/status.h"
#include "lib/jxl/dec_ans.h"
#include "lib/jxl/dec_bit_reader.h"

namespace jxl {

struct ICCReader {
  Status Init(BitReader* reader, size_t output_limit);
  Status Process(BitReader* reader, PaddedBytes* icc);
  void Reset() {
    bits_to_skip_ = 0;
    decompressed_.clear();
  }

 private:
  Status CheckEOI(BitReader* reader);
  size_t i_ = 0;
  size_t bits_to_skip_ = 0;
  size_t used_bits_base_ = 0;
  uint64_t enc_size_ = 0;
  std::vector<uint8_t> context_map_;
  ANSCode code_;
  ANSSymbolReader ans_reader_;
  PaddedBytes decompressed_;
};

// Exposed only for testing
Status PredictICC(const uint8_t* icc, size_t size, PaddedBytes* result);

// Exposed only for testing
Status UnpredictICC(const uint8_t* enc, size_t size, PaddedBytes* result);

}  // namespace jxl

#endif  // LIB_JXL_ICC_CODEC_H_
