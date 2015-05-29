// 16 may 2015
#include "uipriv_windows.h"

struct group {
	uiGroup g;
	HWND hwnd;
};

uiDefineControlType(uiGroup, uiTypeGroup, struct group)

static void groupPreferredSize(uiControl *c, uiSizing *d, intmax_t *width, intmax_t *height)
{
	// TODO
	*width = 0;
	*height = 0;
}

static void groupSetChild(uiGroup *gg, uiControl *c)
{
	// TODO
}

uiGroup *uiNewGroup(const char *text)
{
	struct group *g;
	WCHAR *wtext;

	g = (struct group *) uiWindowsNewSingleHWNDControl(uiTypeGroup());

	wtext = toUTF16(text);
	g->hwnd = uiWindowsNewSingleHWNDControl(WS_EX_CONTROLPARENT,
		L"button", wtext,
		BS_GROUPBOX,
		hInstance, NULL,
		TRUE);
	uiFree(wtext);

	uiControl(g)->PreferredSize = groupPreferredSize;

	uiGroup(g)->SetChild = groupSetChild;

	return uiGroup(g);
}
