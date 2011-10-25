/*
 *  Copyright 2008-2011 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#pragma once

#include <thrust/detail/config.h>

namespace thrust
{
namespace detail
{
namespace backend
{
namespace cuda
{
namespace block
{

template<typename Context,
         typename RandomAccessIterator1,
         typename RandomAccessIterator2,
         typename RandomAccessIterator3,
         typename RandomAccessIterator4,
         typename StrictWeakOrdering>
__device__ __thrust_forceinline__
  RandomAccessIterator4 set_intersection(Context context,
                                         RandomAccessIterator1 first1,
                                         RandomAccessIterator1 last1,
                                         RandomAccessIterator2 first2,
                                         RandomAccessIterator2 last2,
                                         RandomAccessIterator3 temporary,
                                         RandomAccessIterator4 result,
                                         StrictWeakOrdering comp);

} // end namespace block
} // end namespace cuda
} // end namespace backend
} // end namespace detail
} // end namespace thrust

#include <thrust/detail/backend/cuda/block/set_intersection.inl>

