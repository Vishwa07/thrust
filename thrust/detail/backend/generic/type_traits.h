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


/*! \file generic/type_traits.h
 *  \brief Introspection for free functions defined in generic.
 */

#pragma once

#include <thrust/detail/config.h>

namespace thrust
{

// forward declaration of any_space_tag for any_conversion below
struct any_space_tag;

namespace detail
{
namespace backend
{

// we must define these traits outside of generic's namespace
namespace generic_type_traits_ns
{

typedef char yes;
typedef char (&no)[2];

struct any_conversion
{
  template<typename T> any_conversion(const T &);

  // add this extra constructor to disambiguate conversion from any_space_tag
  any_conversion(const any_space_tag &);
};

namespace get_temporary_buffer_exists_ns
{
  template<typename T>
  no get_temporary_buffer(const any_conversion &, const any_conversion &);

  template<typename T> yes check(const T &);

  no check(no);

  template<typename T, typename Tag, typename Size>
    struct get_temporary_buffer_exists
  {
    static Tag  &tag;
    static Size &n;

    static const bool value = sizeof(check(get_temporary_buffer<T>(tag,n))) == sizeof(yes);
  };
} // end get_temporary_buffer_ns

namespace select_system_exists_ns
{
  no select_system(const any_conversion &);
  no select_system(const any_conversion &, const any_conversion &);
  no select_system(const any_conversion &, const any_conversion &, const any_conversion &);
  no select_system(const any_conversion &, const any_conversion &, const any_conversion &, const any_conversion &);

  template<typename T> yes check(const T &);

  no check(no);

  template<typename Tag>
    struct select_system1_exists
  {
    static Tag &tag;

    static const bool value = sizeof(check(select_system(tag))) == sizeof(yes);
  };

  template<typename Tag1, typename Tag2>
    struct select_system2_exists
  {
    static Tag1 &tag1;
    static Tag2 &tag2;

    static const bool value = sizeof(check(select_system(tag1,tag2))) == sizeof(yes);
  };

  template<typename Tag1, typename Tag2, typename Tag3>
    struct select_system3_exists
  {
    static Tag1 &tag1;
    static Tag2 &tag2;
    static Tag3 &tag3;

    static const bool value = sizeof(check(select_system(tag1,tag2,tag3))) == sizeof(yes);
  };

  template<typename Tag1, typename Tag2, typename Tag3, typename Tag4>
    struct select_system4_exists
  {
    static Tag1 &tag1;
    static Tag2 &tag2;
    static Tag3 &tag3;
    static Tag4 &tag4;

    static const bool value = sizeof(check(select_system(tag1,tag2,tag3,tag4))) == sizeof(yes);
  };
} // end select_system_exists_ns

} // end generic_type_traits_ns

namespace generic
{

template<typename T, typename Tag, typename Size>
  struct get_temporary_buffer_exists
    : generic_type_traits_ns::get_temporary_buffer_exists_ns::get_temporary_buffer_exists<T,Tag,Size>
{};

template<typename Tag>
  struct select_system1_exists
    : generic_type_traits_ns::select_system_exists_ns::select_system1_exists<Tag>
{};

template<typename Tag1, typename Tag2>
  struct select_system2_exists
    : generic_type_traits_ns::select_system_exists_ns::select_system2_exists<Tag1,Tag2>
{};

template<typename Tag1, typename Tag2, typename Tag3>
  struct select_system3_exists
    : generic_type_traits_ns::select_system_exists_ns::select_system3_exists<Tag1,Tag2,Tag3>
{};

template<typename Tag1, typename Tag2, typename Tag3, typename Tag4>
  struct select_system4_exists
    : generic_type_traits_ns::select_system_exists_ns::select_system4_exists<Tag1,Tag2,Tag3,Tag4>
{};

} // end generic
} // end backend
} // end detail
} // end thrust

