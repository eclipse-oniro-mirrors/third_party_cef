// Copyright (c) 2022 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//
// $hash=a9e35ca17785f77666db7650208cacfd9a85c3e0$
//

#ifndef CEF_INCLUDE_CAPI_CEF_RESOURCE_BUNDLE_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_RESOURCE_BUNDLE_CAPI_H_
#pragma once

#include "include/capi/cef_base_capi.h"
#include "include/capi/cef_values_capi.h"

#ifdef __cplusplus
extern "C" {
#endif

///
// Structure used for retrieving resources from the resource bundle (*.pak)
// files loaded by CEF during startup or via the cef_resource_bundle_handler_t
// returned from cef_app_t::GetResourceBundleHandler. See CefSettings for
// additional options related to resource bundle loading. The functions of this
// structure may be called on any thread unless otherwise indicated.
///
typedef struct _cef_resource_bundle_t {
  ///
  // Base structure.
  ///
  cef_base_ref_counted_t base;

  ///
  // Returns the localized string for the specified |string_id| or an NULL
  // string if the value is not found. Include cef_pack_strings.h for a listing
  // of valid string ID values.
  ///
  // The resulting string must be freed by calling cef_string_userfree_free().
  cef_string_userfree_t(CEF_CALLBACK* get_localized_string)(
      struct _cef_resource_bundle_t* self,
      int string_id);

  ///
  // Returns a cef_binary_value_t containing the decompressed contents of the
  // specified scale independent |resource_id| or NULL if not found. Include
  // cef_pack_resources.h for a listing of valid resource ID values.
  ///
  struct _cef_binary_value_t*(CEF_CALLBACK* get_data_resource)(
      struct _cef_resource_bundle_t* self,
      int resource_id);

  ///
  // Returns a cef_binary_value_t containing the decompressed contents of the
  // specified |resource_id| nearest the scale factor |scale_factor| or NULL if
  // not found. Use a |scale_factor| value of SCALE_FACTOR_NONE for scale
  // independent resources or call GetDataResource instead.Include
  // cef_pack_resources.h for a listing of valid resource ID values.
  ///
  struct _cef_binary_value_t*(CEF_CALLBACK* get_data_resource_for_scale)(
      struct _cef_resource_bundle_t* self,
      int resource_id,
      cef_scale_factor_t scale_factor);
} cef_resource_bundle_t;

///
// Returns the global resource bundle instance.
///
CEF_EXPORT cef_resource_bundle_t* cef_resource_bundle_get_global();

#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_RESOURCE_BUNDLE_CAPI_H_
