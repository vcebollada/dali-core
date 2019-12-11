/*
 * Copyright (c) 2019 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

// INTERNAL INCLUDE
#include <dali/integration-api/debug.h>

// EXTERNAL INCLUDES
#include <stdint.h>
#include <time.h>

#if defined(DEBUG_ENABLED)

namespace
{
const uint64_t NANOSECONDS_PER_SECOND = 1e+9;
}

namespace Dali
{

namespace Integration
{

namespace Log
{

void GetNanoseconds( uint64_t& timeInNanoseconds )
{
  timespec timeSpec;
  clock_gettime( CLOCK_MONOTONIC, &timeSpec );

  // Convert all values to uint64_t to match our return type
  timeInNanoseconds = ( static_cast< uint64_t >( timeSpec.tv_sec ) * NANOSECONDS_PER_SECOND ) + static_cast< uint64_t >( timeSpec.tv_nsec );
}

} // namespace Debug

} // namespace Integration

} // namespace Dali

#endif // DEBUG_ENABLED
