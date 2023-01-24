#define XF86MonBrightnessDown 0x1008ff03
#define XF86MonBrightnessUp 0x1008ff02
#define TERMINAL "st"
#define TERMCLASS "St"

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 14;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 20;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Hack Nerd Font:size=12", "Noto Color Emoji:pixelsize=12:antialias=true:autohint=true"  };
static const char dmenufont[]       = "Hack Nerd Font:size=12";
static const char normbgcolor[]     = "#140E0A";
static const char normbordercolor[] = "#3E4141";
static const char normfgcolor[]     = "#B4B9BA";
static const char selfgcolor[]      = "#F2F2F2";
static const char selbordercolor[]  = "#770000";
static const char selbgcolor[]      = "#73C1D3";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
	[SchemeSel]  = { normbgcolor, selbgcolor,  selbgcolor  },
	[SchemeTitle]  = { selfgcolor, normbgcolor,  normbordercolor  },
};

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "100x25", NULL };
const char *spcmd2[] = {"st", "-n", "spfm", "-g", "100x25", "-e", "lfub", NULL };
const char *spcmd3[] = {"st", "-n", "spmus", "-g", "100x25", "-e", "ncmpcpp", NULL };
const char *spcmd4[] = {"st", "-n", "spcalz", "-g", "100x25", "-e", "calcurse", NULL };
const char *spcmd5[] = {"st", "-n", "spnmt", "-g", "100x25", "-e", "nmtui", NULL };
const char *spcmd6[] = {"st", "-n", "spcalc", "-f", "monospace:size=16", "-g", "35x20", "-e", "bc", "-lq", NULL };

static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spfm",        spcmd2},
	{"spmus",       spcmd3},
	{"spcalz",      spcmd4},
	{"spnmt",       spcmd5},
	{"spcalc",      spcmd6},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",	  NULL,			  NULL,		0,				1,			 -1 },
	{ "Firefox",  NULL,			NULL,		1 << 8,			0,			 -1 },
	{ NULL,		  "spterm",		NULL,		SPTAG(0),		1,			 -1 },
	{ NULL,		  "spfm",		  NULL,		SPTAG(1),		1,			 -1 },
	{ NULL,		  "spmus",		NULL,		SPTAG(2),		1,			 -1 },
	{ NULL,		  "spcalz",		NULL,		SPTAG(3),		1,			 -1 },
	{ NULL,		  "spnmt",		NULL,		SPTAG(4),		1,			 -1 },
	{ NULL,		  "spcalc",		NULL,		SPTAG(5),		1,			 -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "TTT",      bstack },

	{ "D[]",      deck },
	{ "[@]",      spiral },

	{ "[M]",      monocle },

	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },

	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", normbgcolor, NULL };
static const char *termcmd[]  = { "st", NULL };

#include <X11/XF86keysym.h>
#include "shiftview.c"
#include "movestack.c"

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
  { MODKEY,			XK_i,	shiftview,	{ .i = -1 } },
  { MODKEY,			XK_o,	shiftview,	{ .i = 1 } },
	{ MODKEY,                       XK_n,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_n,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
  { MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = +0.25} },
  { MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = -0.25} },
  { MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_space,  zoom,           {0} },
	{ MODKEY,			XK_z,		incrgaps,	{.i = +3 } },
  { MODKEY,			XK_x,		incrgaps,	{.i = -3 } },
	{ MODKEY,			XK_a,		togglegaps,	{0} },
	{ MODKEY|ShiftMask,		XK_a,		defaultgaps,	{0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_d,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ControlMask,           XK_s,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ControlMask,           XK_m,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[5]} },
	{ MODKEY|ShiftMask,             XK_u,      setlayout,      {.v = &layouts[6]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[7]} },
	{ MODKEY,                       XK_semicolon,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,   XK_Return,  	   togglescratch,  {.ui = 0 } },
	{ MODKEY,             XK_e,  	   togglescratch,  {.ui = 1 } },
	{ MODKEY,             XK_m,	   togglescratch,  {.ui = 2 } },
	{ MODKEY,             XK_c,  togglescratch,  {.ui = 3 } },
	{ MODKEY|ControlMask, XK_n,  togglescratch,  {.ui = 4 } },
	{ MODKEY,             XK_apostrophe,  togglescratch,  {.ui = 5 } },

  /* volume and brightness */
    { 0,  XF86XK_AudioMute,           spawn, SHCMD("changevolume mute") },
    { 0,  XF86XK_AudioRaiseVolume,    spawn, SHCMD("changevolume up") },
    { 0,  XF86XK_AudioLowerVolume,    spawn, SHCMD("changevolume down") },
    { 0,  XF86MonBrightnessUp,        spawn, SHCMD("changebrightness up") },
    { 0,  XF86MonBrightnessDown,      spawn, SHCMD("changebrightness down") },

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
  { MODKEY|ControlMask,           XK_q,      quit,           {1} },  //reload dwm
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {0} },  //quit dwm
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

