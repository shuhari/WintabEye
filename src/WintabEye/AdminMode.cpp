#include "stdafx.h"
#include "AdminMode.h"


// Code from: http://www.cplusplus.com/forum/windows/101207/
BOOL IsRunAsAdmin() {
	BOOL fIsRunAsAdmin = FALSE;
	DWORD dwError = ERROR_SUCCESS;
	PSID pAdminGroup = NULL;

	SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
	if (!AllocateAndInitializeSid(&NtAuthority,
		2,
		SECURITY_BUILTIN_DOMAIN_RID,
		DOMAIN_ALIAS_RID_ADMINS,
		0, 0, 0, 0, 0, 0,
		&pAdminGroup))
		goto cleanup;

	if (!CheckTokenMembership(NULL, pAdminGroup, &fIsRunAsAdmin))
		goto cleanup;

cleanup:
	if (pAdminGroup)
	{
		FreeSid(pAdminGroup);
		pAdminGroup = NULL;
	}
	return fIsRunAsAdmin;
}


BOOL RestartAsAdmin() {
	if (IsRunAsAdmin())
		return TRUE;
	wchar_t szPath[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, szPath, _MAX_PATH);
	SHELLEXECUTEINFO sei = { sizeof(sei) };
	sei.lpVerb = L"runas";
	sei.lpFile = szPath;
	sei.hwnd = NULL;
	sei.nShow = SW_NORMAL;
	return ShellExecuteEx(&sei);
}
