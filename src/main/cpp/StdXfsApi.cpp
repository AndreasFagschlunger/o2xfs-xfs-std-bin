#include "StdXfsApi.h"
#include "at_o2xfs_xfs_std_StdXfsApi.h"
#include "o2xfs-common.h"
#include "o2xfs-logger.h"

o2xfs::Logger LOG;

HINSTANCE hInstance;
HMODULE hinstMsxfsLib;

WFS_CANCEL_ASYNC_REQUEST lpWFSCancelAsyncRequest;
WFS_CANCEL_BLOCKING_CALL lpWFSCancelBlockingCall;
WFS_CLEAN_UP             lpWFSCleanUp;
WFS_CLOSE                lpWFSClose;
WFS_ASYNC_CLOSE          lpWFSAsyncClose;
WFS_CREATE_APP_HANDLE    lpWFSCreateAppHandle;
WFS_DEREGISTER           lpWFSDeregister;
WFS_ASYNC_DEREGISTER     lpWFSAsyncDeregister;
WFS_DESTROY_APP_HANDLE   lpWFSDestroyAppHandle;
WFS_EXECUTE              lpWFSExecute;
WFS_ASYNC_EXECUTE        lpWFSAsyncExecute;
WFS_FREE_RESULT          lpWFSFreeResult;
WFS_GET_INFO             lpWFSGetInfo;
WFS_ASYNC_GET_INFO       lpWFSAsyncGetInfo;
WFS_IS_BLOCKING          lpWFSIsBlocking;
WFS_LOCK                 lpWFSLock;
WFS_ASYNC_LOCK           lpWFSAsyncLock;
WFS_OPEN                 lpWFSOpen;
WFS_ASYNC_OPEN           lpWFSAsyncOpen;
WFS_REGISTER             lpWFSRegister;
WFS_ASYNC_REGISTER       lpWFSAsyncRegister;
WFS_SET_BLOCKING_HOOK    lpWFSSetBlockingHook;
WFS_START_UP             lpWFSStartUp;
WFS_UNHOOK_BLOCKING_HOOK lpWFSUnhookBlockingHook;
WFS_UNLOCK               lpWFSUnlock;
WFS_ASYNC_UNLOCK         lpWFSAsyncUnlock;
WFM_SETTEXTRACE_LEVEL    lpWFMSetTraceLevel;

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
	switch (fdwReason) {
	case DLL_PROCESS_ATTACH:
		LOG.setFileName(TEXT("C:\\Temp\\o2xfs-xfs-std.log"));
		hInstance = hinstDLL;
		break;
	case DLL_PROCESS_DETACH:
		LOG.debug(TEXT("DLL_PROCESS_DETACH"));
		if (hinstMsxfsLib != NULL) {
			FreeLibrary(hinstMsxfsLib);
		}
		break;
	}
	return TRUE;
}

JNIEXPORT void JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_loadLibrary0(JNIEnv *env, jobject obj) {
	hinstMsxfsLib = LoadLibrary(TEXT("msxfs.dll"));
	if (hinstMsxfsLib == NULL) {
		LOG.error(TEXT("Error loading msxfs.dll: %d"), GetLastError()); // FIXME: Error handling
		return;
	}
	lpWFSCancelAsyncRequest = (WFS_CANCEL_ASYNC_REQUEST)GetProcAddress(hinstMsxfsLib, "WFSCancelAsyncRequest");
	lpWFSCancelBlockingCall = (WFS_CANCEL_BLOCKING_CALL)GetProcAddress(hinstMsxfsLib, "WFSCancelBlockingCall");
	lpWFSCleanUp = (WFS_CLEAN_UP)GetProcAddress(hinstMsxfsLib, "WFSCleanUp");
	lpWFSClose = (WFS_CLOSE)GetProcAddress(hinstMsxfsLib, "WFSClose");
	lpWFSAsyncClose = (WFS_ASYNC_CLOSE)GetProcAddress(hinstMsxfsLib, "WFSAsyncClose");
	lpWFSCreateAppHandle = (WFS_CREATE_APP_HANDLE)GetProcAddress(hinstMsxfsLib, "WFSCreateAppHandle");
	lpWFSDeregister = (WFS_DEREGISTER)GetProcAddress(hinstMsxfsLib, "WFSDeregister");
	lpWFSAsyncDeregister = (WFS_ASYNC_DEREGISTER)GetProcAddress(hinstMsxfsLib, "WFSAsyncDeregister");
	lpWFSDestroyAppHandle = (WFS_DESTROY_APP_HANDLE)GetProcAddress(hinstMsxfsLib, "WFSDestroyAppHandle");
	lpWFSExecute = (WFS_EXECUTE)GetProcAddress(hinstMsxfsLib, "WFSExecute");
	lpWFSAsyncExecute = (WFS_ASYNC_EXECUTE)GetProcAddress(hinstMsxfsLib, "WFSAsyncExecute");
	lpWFSFreeResult = (WFS_FREE_RESULT)GetProcAddress(hinstMsxfsLib, "WFSFreeResult");
	lpWFSGetInfo = (WFS_GET_INFO)GetProcAddress(hinstMsxfsLib, "WFSGetInfo");
	lpWFSAsyncGetInfo = (WFS_ASYNC_GET_INFO)GetProcAddress(hinstMsxfsLib, "WFSAsyncGetInfo");
	lpWFSIsBlocking = (WFS_IS_BLOCKING)GetProcAddress(hinstMsxfsLib, "WFSIsBlocking");
	lpWFSLock = (WFS_LOCK)GetProcAddress(hinstMsxfsLib, "WFSLock");
	lpWFSAsyncLock = (WFS_ASYNC_LOCK)GetProcAddress(hinstMsxfsLib, "WFSAsyncLock");
	lpWFSOpen = (WFS_OPEN)GetProcAddress(hinstMsxfsLib, "WFSOpen");
	lpWFSAsyncOpen = (WFS_ASYNC_OPEN)GetProcAddress(hinstMsxfsLib, "WFSAsyncOpen");
	lpWFSRegister = (WFS_REGISTER)GetProcAddress(hinstMsxfsLib, "WFSRegister");
	lpWFSAsyncRegister = (WFS_ASYNC_REGISTER)GetProcAddress(hinstMsxfsLib, "WFSAsyncRegister");
	lpWFSSetBlockingHook = (WFS_SET_BLOCKING_HOOK)GetProcAddress(hinstMsxfsLib, "WFSSetBlockingHook");
	lpWFSStartUp = (WFS_START_UP)GetProcAddress(hinstMsxfsLib, "WFSStartUp");
	lpWFSUnhookBlockingHook = (WFS_UNHOOK_BLOCKING_HOOK)GetProcAddress(hinstMsxfsLib, "WFSUnhookBlockingHook");
	lpWFSUnlock = (WFS_UNLOCK)GetProcAddress(hinstMsxfsLib, "WFSUnlock");
	lpWFSAsyncUnlock = (WFS_ASYNC_UNLOCK)GetProcAddress(hinstMsxfsLib, "WFSAsyncUnlock");
	lpWFMSetTraceLevel = (WFM_SETTEXTRACE_LEVEL)GetProcAddress(hinstMsxfsLib, "WFMSetTraceLevel");
}

JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsCancelAsyncRequest(JNIEnv *env, jobject obj, jbyteArray hServiceObj, jbyteArray RequestIdObj) {
	HSERVICE hService = *(LPHSERVICE) o2xfs::ToPointer(env, hServiceObj);
	REQUESTID RequestID = *(LPREQUESTID) o2xfs::ToPointer(env, RequestIdObj);
	LOG.debug(TEXT("WFSCancelAsyncRequest: hService=%d,RequestID=%d"), hService, RequestID);
	return lpWFSCancelAsyncRequest(hService, RequestID);
}

JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsAsyncClose(JNIEnv *env, jobject obj, jbyteArray hServiceObj, jbyteArray hWndObj, jbyteArray lpRequestIdObj) {
	HSERVICE hService = *(LPHSERVICE) o2xfs::ToPointer(env, hServiceObj);
	HWND hWnd = (HWND) o2xfs::ToPointer(env, hWndObj);
	LPREQUESTID lpRequestId = (LPREQUESTID) o2xfs::ToPointer(env, lpRequestIdObj);
	LOG.debug(TEXT("WFSAsyncClose: hService=%d,hWnd=%p,lpRequestId=%p"), hService, hWnd, lpRequestId);
	return lpWFSAsyncClose(hService, hWnd, lpRequestId);
}

JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsAsyncDeregister(JNIEnv *env, jobject obj, jbyteArray hServiceObj, jbyteArray dwEventClassObj, jbyteArray hWndRegObj, jbyteArray hWndObj, jbyteArray lpRequestIdObj) {
	HSERVICE hService = *(LPHSERVICE) o2xfs::ToPointer(env, hServiceObj);
	DWORD dwEventClass = *(LPDWORD) o2xfs::ToPointer(env, dwEventClassObj);
	HWND hWndReg = (HWND) o2xfs::ToPointer(env, hWndRegObj);
	HWND hWnd = (HWND) o2xfs::ToPointer(env, hWndObj);
	LPREQUESTID lpRequestId = (LPREQUESTID) o2xfs::ToPointer(env, lpRequestIdObj);
	LOG.debug(TEXT("WFSAsyncDeregister: hService=%d,dwEventClass=%d,hWndReg=%p,hWnd=%p,lpRequestId=%p"), hService, dwEventClass, hWndReg, hWnd, lpRequestId);
	return lpWFSAsyncDeregister(hService, dwEventClass, hWndReg, hWnd, lpRequestId);
}

JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsAsyncExecute(JNIEnv *env, jobject obj, jbyteArray hServiceObj, jbyteArray dwCommandObj, jbyteArray lpCmdDataObj, jbyteArray dwTimeOutObj, jbyteArray hWndObj, jbyteArray lpRequestIdObj) {
	HSERVICE hService = *(LPHSERVICE) o2xfs::ToPointer(env, hServiceObj);
	DWORD dwCommand = *(LPDWORD) o2xfs::ToPointer(env, dwCommandObj);
	LPVOID lpCmdData = lpCmdDataObj == NULL ? NULL : o2xfs::ToPointer(env, lpCmdDataObj);
	DWORD dwTimeOut = *(LPDWORD) o2xfs::ToPointer(env, dwTimeOutObj);
	HWND hWnd = (HWND) o2xfs::ToPointer(env, hWndObj);
	LPREQUESTID lpRequestId = (LPREQUESTID) o2xfs::ToPointer(env, lpRequestIdObj);
	LOG.debug(TEXT("WFSAsyncExecute: hService=%d,dwCommand=%d,lpCmdData=%p,dwTimeOut=%d,hWnd=%p,lpRequestId=%p"), hService, dwCommand, lpCmdData, dwTimeOut, hWnd, lpRequestId);
	return lpWFSAsyncExecute(hService, dwCommand, lpCmdData, dwTimeOut, hWnd, lpRequestId);
}

JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsAsyncGetInfo(JNIEnv *env, jobject obj, jbyteArray hServiceObj, jbyteArray dwCategoryObj, jbyteArray lpQueryDetailsObj, jbyteArray dwTimeOutObj, jbyteArray hWndObj, jbyteArray lpRequestIdObj) {
	HSERVICE hService = *(LPHSERVICE) o2xfs::ToPointer(env, hServiceObj);
	DWORD dwCategory = *(LPDWORD) o2xfs::ToPointer(env, dwCategoryObj);
	LPVOID lpQueryDetails = lpQueryDetailsObj == NULL ? NULL : o2xfs::ToPointer(env, lpQueryDetailsObj);
	DWORD dwTimeOut = *(LPDWORD) o2xfs::ToPointer(env, dwTimeOutObj);
	HWND hWnd = (HWND) o2xfs::ToPointer(env, hWndObj);
	LPREQUESTID lpRequestId = (LPREQUESTID) o2xfs::ToPointer(env, lpRequestIdObj);
	LOG.debug(TEXT("WFSAsyncGetInfo: hService=%d,dwCategory=%d,lpQueryDetails=%p,dwTimeOut=%d,hWnd=%p,lpRequestId=%p"), hService, dwCategory, lpQueryDetails, dwTimeOut, hWnd, lpRequestId);
	return lpWFSAsyncGetInfo(hService, dwCategory, lpQueryDetails, dwTimeOut, hWnd, lpRequestId);
}

JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsAsyncLock(JNIEnv *env, jobject obj, jbyteArray hServiceObj, jbyteArray dwTimeOutObj, jbyteArray hWndObj, jbyteArray lpRequestIdObj) {
	HSERVICE hService = *(LPHSERVICE) o2xfs::ToPointer(env, hServiceObj);
	DWORD dwTimeOut = *(LPDWORD) o2xfs::ToPointer(env, dwTimeOutObj);
	HWND hWnd = (HWND) o2xfs::ToPointer(env, hWndObj);
	LPREQUESTID lpRequestId = (LPREQUESTID) o2xfs::ToPointer(env, lpRequestIdObj);
	LOG.debug(TEXT("WFSAsyncLock: hService=%d,dwTimeOut=%d,hWnd=%p,lpRequestId=%p"), hService, dwTimeOut, hWnd, lpRequestId);
	return lpWFSAsyncLock(hService, dwTimeOut, hWnd, lpRequestId);
}

JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsAsyncOpen(JNIEnv *env, jobject obj, jbyteArray lpszLogicalNameObj, jbyteArray hAppObj, jbyteArray lpszAppIdObj, jbyteArray dwTraceLevelObj, jbyteArray dwTimeOutObj, jbyteArray lphServiceObj, jbyteArray hWndObj, jbyteArray dwSrvcVersionsRequiredObj, jbyteArray lpSrvcVersionObj, jbyteArray lpSpiVersionObj, jbyteArray lpRequestIdObj) {
	LPSTR lpszLogicalName = *(LPSTR*) o2xfs::ToPointer(env, lpszLogicalNameObj);
	HAPP hApp = hAppObj == NULL ? WFS_DEFAULT_HAPP : *(LPHAPP) o2xfs::ToPointer(env, hAppObj);
	LPSTR lpszAppID = lpszAppIdObj == NULL ? NULL : *(LPSTR*) o2xfs::ToPointer(env, lpszAppIdObj);
	DWORD dwTraceLevel = *(LPDWORD) o2xfs::ToPointer(env, dwTraceLevelObj);
	DWORD dwTimeOut = *(LPDWORD) o2xfs::ToPointer(env, dwTimeOutObj);
	LPHSERVICE lphService = (LPHSERVICE) o2xfs::ToPointer(env, lphServiceObj);
	HWND hWnd = (HWND) o2xfs::ToPointer(env, hWndObj);
	DWORD dwSrvcVersionsRequired = *(LPDWORD) o2xfs::ToPointer(env, dwSrvcVersionsRequiredObj);
	LPWFSVERSION lpSrvcVersion = (LPWFSVERSION) o2xfs::ToPointer(env, lpSrvcVersionObj);
	LPWFSVERSION lpSPIVersion = (LPWFSVERSION) o2xfs::ToPointer(env, lpSpiVersionObj);
	LPREQUESTID lpRequestId = (LPREQUESTID) o2xfs::ToPointer(env, lpRequestIdObj);
	LOG.debug(TEXT("WFSAsyncOpen: lpszLogicalName=%hs,hApp=%p,lpszAppID=%hs,dwTraceLevel=%d,dwTimeOut=%d,lphService=%p,hWnd=%p,dwSrvcVersionsRequired=%d,lpSrvcVersion=%p,lpSPIVersion=%p,lpRequestId=%p"), lpszLogicalName, hApp, lpszAppID, dwTraceLevel, dwTimeOut, lphService, hWnd, dwSrvcVersionsRequired, lpSrvcVersion, lpSPIVersion, lpRequestId);
	return lpWFSAsyncOpen(lpszLogicalName, hApp, lpszAppID, dwTraceLevel, dwTimeOut, lphService, hWnd, dwSrvcVersionsRequired, lpSrvcVersion, lpSPIVersion, lpRequestId);
}

JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsAsyncRegister(JNIEnv* env, jobject obj, jbyteArray hServiceObj, jbyteArray dwEventClassObj, jbyteArray hWndRegObj, jbyteArray hWndObj, jbyteArray lpRequestIdObj) {
	HSERVICE hService = *(LPHSERVICE) o2xfs::ToPointer(env, hServiceObj);
	DWORD dwEventClass = *(LPDWORD) o2xfs::ToPointer(env, dwEventClassObj);
	HWND hWndReg = (HWND) o2xfs::ToPointer(env, hWndRegObj);
	HWND hWnd = (HWND) o2xfs::ToPointer(env, hWndObj);
	LPREQUESTID lpRequestId = (LPREQUESTID) o2xfs::ToPointer(env, lpRequestIdObj);
	LOG.debug(TEXT("WFSAsyncRegister: hService=%d,dwEventClass=%d,hWndReg=%p,hWnd=%p,lpRequestId=%p"), hService, dwEventClass, hWndReg, hWnd, lpRequestId);
	return lpWFSAsyncRegister(hService, dwEventClass, hWndReg, hWnd, lpRequestId);
}

JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsAsyncUnlock(JNIEnv* env, jobject obj, jbyteArray hServiceObj, jbyteArray hWndObj, jbyteArray lpRequestIdObj) {
	HSERVICE hService = *(LPHSERVICE) o2xfs::ToPointer(env, hServiceObj);
	HWND hWnd = (HWND) o2xfs::ToPointer(env, hWndObj);
	LPREQUESTID lpRequestId = (LPREQUESTID) o2xfs::ToPointer(env, lpRequestIdObj);
	LOG.debug(TEXT("WFSAsyncUnlock: hService=%d,hWnd=%p,lpRequestId=%p"), hService, hWnd, lpRequestId);
	return lpWFSAsyncUnlock(hService, hWnd, lpRequestId);
}

JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsCleanUp(JNIEnv* env, jobject obj) {
	LOG.debug(TEXT("WFSCleanUp"));
	return lpWFSCleanUp();
}

JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsCreateAppHandle(JNIEnv* env, jobject obj, jbyteArray lphAppObj) {
	LPHAPP lphApp = (LPHAPP) o2xfs::ToPointer(env, lphAppObj);
	HRESULT result = lpWFSCreateAppHandle(lphApp);
	LOG.debug(TEXT("WFSCreateAppHandle: hApp=%p"), *lphApp);
	return result;
}

JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsDestroyAppHandle(JNIEnv *env, jobject obj, jbyteArray hAppObj) {
	HAPP hApp = (HAPP) o2xfs::ToPointer(env, hAppObj);
	LOG.debug(TEXT("WFSDestroyAppHandle: hApp=%p"), hApp);
	return lpWFSDestroyAppHandle(hApp);
}

JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsFreeResult(JNIEnv* env, jobject obj, jbyteArray lpResultObj) {
	LPWFSRESULT lpResult = (LPWFSRESULT) o2xfs::ToPointer(env, lpResultObj);
	LOG.debug(TEXT("WFSFreeResult: lpResult=%p"), lpResult);
	return lpWFSFreeResult(lpResult);
}

JNIEXPORT jboolean JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsIsBlocking(JNIEnv *env, jobject obj) {
	return lpWFSIsBlocking();
}

JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfmSetTraceLevel(JNIEnv *env, jobject obj, jbyteArray hServiceObj, jbyteArray dwTraceLevelObj) {
	HSERVICE hService = *(LPHSERVICE) o2xfs::ToPointer(env, hServiceObj);
	DWORD dwTraceLevel = *(LPDWORD) o2xfs::ToPointer(env, dwTraceLevelObj);
	LOG.debug(TEXT("WFPSetTraceLevel: hService=%d,dwTraceLevel=%d"), hService, dwTraceLevel);
	return lpWFMSetTraceLevel(hService, dwTraceLevel);
}

JNIEXPORT jint JNICALL Java_at_o2xfs_xfs_std_StdXfsApi_wfsStartUp(JNIEnv *env, jobject obj, jbyteArray dwVersionsRequiredObj, jbyteArray lpWfsVersionObj) {
	DWORD dwVersionsRequired = *(LPDWORD) o2xfs::ToPointer(env, dwVersionsRequiredObj);
	LPWFSVERSION lpWfsVersion = (LPWFSVERSION) o2xfs::ToPointer(env, lpWfsVersionObj);
	LOG.debug(TEXT("WFSStartUp: %d.%d - %d.%d"), LOBYTE(HIWORD(dwVersionsRequired)), HIBYTE(HIWORD(dwVersionsRequired)), LOBYTE(LOWORD(dwVersionsRequired)), HIBYTE(LOWORD(dwVersionsRequired)));
	return lpWFSStartUp(dwVersionsRequired, lpWfsVersion);
}