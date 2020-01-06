// Licensed to the Apache Software Foundation (ASF) under one
// or more contributor license agreements.  See the NOTICE file
// distributed with this work for additional information
// regarding copyright ownership.  The ASF licenses this file
// to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance
// with the License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing,
// software distributed under the License is distributed on an
// "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied.  See the License for the
// specific language governing permissions and limitations
// under the License.

#pragma once

#include <string>

#include "segment/Types.h"
#include "store/Directory.h"
#include "utils/Status.h"

namespace milvus {
namespace segment {

class SegmentReader {
 public:
    explicit SegmentReader(const std::string& directory);

    // TODO(zhiru)
    Status
    LoadCache(bool& in_cache);

    Status
    LoadFromDisk();

    Status
    LoadUids(std::vector<doc_id_t>& uids);

    Status
    LoadBloomFilter(segment::IdBloomFilterPtr& id_bloom_filter_ptr);

    Status
    GetSegment(SegmentPtr& segment_ptr);

 private:
    store::DirectoryPtr directory_ptr_;
    SegmentPtr segment_ptr_;
};

using SegmentReaderPtr = std::shared_ptr<SegmentReader>;

}  // namespace segment
}  // namespace milvus
