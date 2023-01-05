// Copyright (c) 2022 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//
// $hash=33a691883b3956a4e2fa2937ab8dc42dc80d78c8$
//

#include "libcef_dll/ctocpp/media_router_ctocpp.h"
#include "libcef_dll/cpptoc/completion_callback_cpptoc.h"
#include "libcef_dll/cpptoc/media_observer_cpptoc.h"
#include "libcef_dll/cpptoc/media_route_create_callback_cpptoc.h"
#include "libcef_dll/ctocpp/media_sink_ctocpp.h"
#include "libcef_dll/ctocpp/media_source_ctocpp.h"
#include "libcef_dll/ctocpp/registration_ctocpp.h"
#include "libcef_dll/shutdown_checker.h"

// STATIC METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
CefRefPtr<CefMediaRouter> CefMediaRouter::GetGlobalMediaRouter(
    CefRefPtr<CefCompletionCallback> callback) {
  shutdown_checker::AssertNotShutdown();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Unverified params: callback

  // Execute
  cef_media_router_t* _retval =
      cef_media_router_get_global(CefCompletionCallbackCppToC::Wrap(callback));

  // Return type: refptr_same
  return CefMediaRouterCToCpp::Wrap(_retval);
}

// VIRTUAL METHODS - Body may be edited by hand.

NO_SANITIZE("cfi-icall")
CefRefPtr<CefRegistration> CefMediaRouterCToCpp::AddObserver(
    CefRefPtr<CefMediaObserver> observer) {
  shutdown_checker::AssertNotShutdown();

  cef_media_router_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, add_observer))
    return nullptr;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: observer; type: refptr_diff
  DCHECK(observer.get());
  if (!observer.get())
    return nullptr;

  // Execute
  cef_registration_t* _retval =
      _struct->add_observer(_struct, CefMediaObserverCppToC::Wrap(observer));

  // Return type: refptr_same
  return CefRegistrationCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall")
CefRefPtr<CefMediaSource> CefMediaRouterCToCpp::GetSource(
    const CefString& urn) {
  shutdown_checker::AssertNotShutdown();

  cef_media_router_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, get_source))
    return nullptr;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: urn; type: string_byref_const
  DCHECK(!urn.empty());
  if (urn.empty())
    return nullptr;

  // Execute
  cef_media_source_t* _retval = _struct->get_source(_struct, urn.GetStruct());

  // Return type: refptr_same
  return CefMediaSourceCToCpp::Wrap(_retval);
}

NO_SANITIZE("cfi-icall") void CefMediaRouterCToCpp::NotifyCurrentSinks() {
  shutdown_checker::AssertNotShutdown();

  cef_media_router_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, notify_current_sinks))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->notify_current_sinks(_struct);
}

NO_SANITIZE("cfi-icall")
void CefMediaRouterCToCpp::CreateRoute(
    CefRefPtr<CefMediaSource> source,
    CefRefPtr<CefMediaSink> sink,
    CefRefPtr<CefMediaRouteCreateCallback> callback) {
  shutdown_checker::AssertNotShutdown();

  cef_media_router_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, create_route))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Verify param: source; type: refptr_same
  DCHECK(source.get());
  if (!source.get())
    return;
  // Verify param: sink; type: refptr_same
  DCHECK(sink.get());
  if (!sink.get())
    return;
  // Verify param: callback; type: refptr_diff
  DCHECK(callback.get());
  if (!callback.get())
    return;

  // Execute
  _struct->create_route(_struct, CefMediaSourceCToCpp::Unwrap(source),
                        CefMediaSinkCToCpp::Unwrap(sink),
                        CefMediaRouteCreateCallbackCppToC::Wrap(callback));
}

NO_SANITIZE("cfi-icall") void CefMediaRouterCToCpp::NotifyCurrentRoutes() {
  shutdown_checker::AssertNotShutdown();

  cef_media_router_t* _struct = GetStruct();
  if (CEF_MEMBER_MISSING(_struct, notify_current_routes))
    return;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  _struct->notify_current_routes(_struct);
}

// CONSTRUCTOR - Do not edit by hand.

CefMediaRouterCToCpp::CefMediaRouterCToCpp() {}

// DESTRUCTOR - Do not edit by hand.

CefMediaRouterCToCpp::~CefMediaRouterCToCpp() {
  shutdown_checker::AssertNotShutdown();
}

template <>
cef_media_router_t*
CefCToCppRefCounted<CefMediaRouterCToCpp, CefMediaRouter, cef_media_router_t>::
    UnwrapDerived(CefWrapperType type, CefMediaRouter* c) {
  NOTREACHED() << "Unexpected class type: " << type;
  return nullptr;
}

template <>
CefWrapperType CefCToCppRefCounted<CefMediaRouterCToCpp,
                                   CefMediaRouter,
                                   cef_media_router_t>::kWrapperType =
    WT_MEDIA_ROUTER;
