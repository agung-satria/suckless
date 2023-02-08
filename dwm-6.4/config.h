#define XF86MonBrightnessDown 0x1008ff03
#define XF86MonBrightnessUp 0x1008ff02
#define TERMINAL "st"
#define TERMCLASS "St"

/* alt-tab configuration */
static const unsigned int tabModKey 		= 0x40;	/* if this key is hold the alt-tab functionality stays acitve. This key must be the same as key that is used to active functin altTabStart `*/
static const unsigned int tabCycleKey 		= 0x17;	/* if this key is hit the alt-tab program moves one position forward in clients stack. This key must be the same as key that is used to active functin altTabStart */
static const unsigned int tabPosY 			= 1;	/* tab position on Y axis, 0 = bottom, 1 = center, 2 = top */
static const unsigned int tabPosX 			= 1;	/* tab position on X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxWTab 			= 600;	/* tab menu width */
static const unsigned int maxHTab 			= 200;	/* tab menu height */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 8;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 8;       /* vert inner gap between windows */
static const unsigned int gappoh    = 8;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 8;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static       int showsystray        = 0;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]        = {"SF Pro Display:weight=Medium:size=14:antialias=true:autohint=true",
  "Hack Nerd Font:style:medium:size=14:autohint=true",
  "JoyPixels:size=12:antialias=true:autohint=true",
  "Noto Color Emoji:pixelsize=12:antialias=true:autohint=true"};

static const char dmenufont[]     = "SF Pro Display:weight=Medium:size=14:antialias=true:autohint=true";

static const char normbgcolor[]     = "#140E0A";
static const char normbordercolor[] = "#3E4141";
static const char normfgcolor[]     = "#B4B9BA";
static const char selfgcolor[]      = "#F2F2F2";
static const char selbgcolor[]      = "#73C1D3";
static const char *colors[][3]      = {
  /*               fg         bg         border   */
  [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
  [SchemeSel]  = { selbgcolor, normbordercolor,  selbgcolor  },
  [SchemeTitle]  = { selfgcolor, normbgcolor,  normbordercolor  },
};

typedef struct {
  const char *name;
  const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "95x28", NULL };
const char *spcmd2[] = {"st", "-n", "spfm", "-g", "95x28", "-e", "lfub", NULL };
const char *spcmd3[] = {"st", "-n", "spmus", "-g", "95x28", "-e", "ncmpcpp", NULL };
const char *spcmd4[] = {"st", "-n", "spcalz", "-g", "95x28", "-e", "calcurse", NULL };
const char *spcmd5[] = {"st", "-n", "spnmt", "-g", "95x28", "-e", "nmtui", NULL };
const char *spcmd6[] = {"st", "-n", "spcalc", "-f", "monospace:size=16", "-g", "35x20", "-e", "bc", "-lq", NULL };
const char *spcmd7[] = {"crow", NULL };

static Sp scratchpads[] = {
  /* name          cmd  */
  {"spterm",      spcmd1},
  {"spfm",        spcmd2},
  {"spmus",       spcmd3},
  {"spcalz",      spcmd4},
  {"spnmt",       spcmd5},
  {"spcalc",      spcmd6},
  {"spcrow",      spcmd7},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
  /* xprop(1):
   *	WM_CLASS(STRING) = instance, class
   *	WM_NAME(STRING) = title
   */
	/* class      instance    title   tags mask     isterminal  isfloating iscentered   noswallow  monitor */
  { "Gimp",	    NULL,			  NULL,		  1 << 5,	    	   0,         0,        0,            0,		   -1 },
  { "Yad",	    NULL,			  NULL,		  0,			         0,        -1,        0,            1,		   -1 },
  { "Arandr",	  NULL,			  NULL,		  0,			         0,        -1,        0,            1,		   -1 },
  { "xdman-Main", NULL,		  NULL,		  0,			         0,        -1,        0,            1,		   -1 },
  { "SimpleScreenRecorder", NULL,NULL,0,			         0,        -1,        0,            1,		   -1 },
  { "Galculator",NULL,			NULL,		  0,			         0,        -1,        0,            1,		   -1 },
  { "Dragon-drop",NULL,		  NULL,		  0,			         0,        -1,        0,            1,		   -1 },
  { "float-st", NULL,       NULL,     0,               1,         1,        1,            0,       -1 },
	{ "St",       NULL,       NULL,     0,               1,         0,        1,            0,       -1 },

  { NULL,		    "spterm",		NULL,		  SPTAG(0),   	   1,         1,        0,            1,			 -1 },
  { NULL,		    "spfm",		  NULL,		  SPTAG(1),   	   1,         1,        0,            1,			 -1 },
  { NULL,		    "spmus",		NULL,		  SPTAG(2),   	   1,         1,        0,            1,			 -1 },
  { NULL,		    "spcalz",		NULL,		  SPTAG(3),   	   1,         1,        0,            1,			 -1 },
  { NULL,		    "spnmt",		NULL,		  SPTAG(4),   	   1,         1,        0,            1,			 -1 },
  { NULL,		    "spcalc",		NULL,		  SPTAG(5),   	   1,         1,        0,            1,			 -1 },
  { NULL,		    "crow",     NULL,     SPTAG(6),   	   1,         1,        0,            1,			 -1 },
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
static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", normbgcolor, "-nf", selfgcolor, "-sb", normbordercolor, "-sf", selbgcolor, NULL };
static const char *termcmd[]  = { "st", NULL };

#include <X11/XF86keysym.h>
#include "shiftview.c"
#include "movestack.c"

static const Key keys[] = {
  /* modifier                     key        function        argument */
  { MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
  { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
  { ALTKEY,                       XK_Return, spawn,		        SHCMD("kitty") }, // kitty or alacritty
  { MODKEY,                       XK_b,      togglebar,      {0} },
  { MODKEY,                       XK_g,      togglesystray,  {0} },
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
	{ MODKEY,			XK_s,		togglesticky,	{0} },
  { MODKEY,                       XK_Tab,    view,           {0} },
  { MODKEY,                       XK_q,      killclient,     {0} },
  { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
  { MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[1]} },
  { MODKEY|ShiftMask,             XK_d,      setlayout,      {.v = &layouts[2]} },
  { MODKEY|ControlMask,           XK_s,      setlayout,      {.v = &layouts[3]} },
  { MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[4]} },
  { MODKEY,                       XK_u,      setlayout,      {.v = &layouts[5]} },
  { MODKEY|ShiftMask,             XK_u,      setlayout,      {.v = &layouts[6]} },
  { MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[7]} },
  { MODKEY,                       XK_semicolon,  setlayout,      {0} },
  { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_f,      togglefullscreen, {0} },
  // Move resize
	{ MODKEY,                       XK_Down,   moveresize,     {.v = "0x 25y 0w 0h" } },
	{ MODKEY,                       XK_Up,     moveresize,     {.v = "0x -25y 0w 0h" } },
	{ MODKEY,                       XK_Right,  moveresize,     {.v = "25x 0y 0w 0h" } },
	{ MODKEY,                       XK_Left,   moveresize,     {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = "0x 0y 0w 25h" } },
	{ MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = "0x 0y 0w -25h" } },
	{ MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = "0x 0y 25w 0h" } },
	{ MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ControlMask,           XK_Up,     moveresizeedge, {.v = "t"} },
	{ MODKEY|ControlMask,           XK_Down,   moveresizeedge, {.v = "b"} },
	{ MODKEY|ControlMask,           XK_Left,   moveresizeedge, {.v = "l"} },
	{ MODKEY|ControlMask,           XK_Right,  moveresizeedge, {.v = "r"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Up,     moveresizeedge, {.v = "T"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Down,   moveresizeedge, {.v = "B"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Left,   moveresizeedge, {.v = "L"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Right,  moveresizeedge, {.v = "R"} },
  { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
  { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
  { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
  { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
  { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
  { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ ALTKEY,             XK_Tab,    altTabStart,	   {0} },
  { MODKEY|ShiftMask,   XK_Return,  	   togglescratch,  {.ui = 0 } },
  { MODKEY,             XK_e,  	   togglescratch,  {.ui = 1 } },
  { MODKEY,             XK_m,	   togglescratch,  {.ui = 2 } },
  { MODKEY,             XK_c,  togglescratch,  {.ui = 3 } },
  { MODKEY|ControlMask, XK_n,  togglescratch,  {.ui = 4 } },
  { MODKEY,             XK_apostrophe,  togglescratch,  {.ui = 5 } },
  { MODKEY,             XK_slash,  togglescratch,  {.ui = 6 } },

  /* volume and brightness */
  { 0,  XF86XK_AudioMute,           spawn, SHCMD("pamixer -t; pkill -RTMIN+1 dwmblocks") },
  { 0,  XF86XK_AudioRaiseVolume,    spawn, SHCMD("pamixer -i 5; pkill -RTMIN+1 dwmblocks") },
  { 0,  XF86XK_AudioLowerVolume,    spawn, SHCMD("pamixer -d 5; pkill -RTMIN+1 dwmblocks") },
  { 0,  XF86MonBrightnessUp,        spawn, SHCMD("light -A 5") },
  { 0,  XF86MonBrightnessDown,      spawn, SHCMD("light -U 5") },

  /* mpd control */
  { MODKEY,			        XK_backslash,		spawn,		SHCMD("mpc -p 6601 toggle") },
  { MODKEY|ShiftMask,			XK_backslash,		spawn,		SHCMD("mpc -p 6601 stop") },
  { MODKEY,			        XK_bracketleft,	    	spawn,		SHCMD("mpc -p 6601 prev") },
  { MODKEY,			        XK_bracketright,	spawn,		SHCMD("mpc -p 6601 next") },
  { MODKEY|ShiftMask,			XK_bracketleft,		spawn,		SHCMD("mpc -p 6601 seek -5") },
  { MODKEY|ShiftMask,			XK_bracketright,	spawn,		SHCMD("mpc -p 6601 seek +5") },
  { MODKEY|ControlMask,		XK_bracketleft,		spawn,		SHCMD("mpc -p 6601 seek -30") },
  { MODKEY|ControlMask,		XK_bracketright,	spawn,		SHCMD("mpc -p 6601 seek +30") },
  { MODKEY|ALTKEY,		    	XK_bracketleft,	    	spawn,		SHCMD("mpc -p 6601 seek 0%") },
  { MODKEY|ALTKEY,		    	XK_bracketright,	spawn,		SHCMD("mpc -p 6601 random") },

  // Apps and scripts

  { MODKEY,			                  XK_w,		   spawn,		SHCMD("$BROWSER") },
  { MODKEY|ShiftMask,		          XK_w,		   spawn,		SHCMD("$BROWSER --private-window") },
  { MODKEY|ShiftMask,		          XK_e,		   spawn,		SHCMD("$FMGR ~/") },
  { MODKEY|ShiftMask,		          XK_apostrophe,spawn,SHCMD("galculator") },

  { MODKEY,				    XK_r,        spawn,		SHCMD("rofi -show drun") },
  { MODKEY,				    XK_y,        spawn,		SHCMD("xcpc") },
  { MODKEY,				    XK_Escape,        spawn,		SHCMD("sysact") },
  // { MODKEY,           XK_BackSpace,     	spawn,		SHCMD("slock") },
  { MODKEY,           XK_BackSpace,     	spawn,		SHCMD("betterlockscreen -l") },
  { MODKEY,				    XK_grave,        spawn,		SHCMD("dmenuunicode") },
  { MODKEY,				    XK_F1,        spawn,		SHCMD("dmenutodo") }, // type something to create new, select todo list to remove list
  { MODKEY,				    XK_F3,        spawn,		SHCMD("dmenuhandler") },
  { MODKEY,				    XK_v,        spawn,		SHCMD("dmenurecord") },
  { MODKEY,				    XK_p,        spawn,		SHCMD("arandr") },
  { MODKEY,			      XK_F4,		      spawn,		SHCMD(TERMINAL " -c float-st -g 95x28 -e pulsemixer") },
  { MODKEY|ShiftMask,	XK_r,        spawn,	    SHCMD(TERMINAL " -c float-st -g 95x28 -e gotop") },
  { MODKEY,			      XK_F11,		spawn,		SHCMD("mpv --untimed --no-cache --no-osc --no-input-default-bindings --profile=low-latency --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },
  { MODKEY|ControlMask, XK_Return,  spawn,		SHCMD("$TERMINAL -e runtmux") },

  { 0,			       XK_Print,	spawn,		SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png && notify-send '🖼️ Screenshot saved'") },
  { ShiftMask,	       	       XK_Print,	spawn,		SHCMD("maimpick") },
  { ControlMask,         	       XK_Print,	spawn,		SHCMD("maim | xclip -selection clipboard -t image/png && notify-send '📋 Screenshot copied to clipboard'") },
  { MODKEY|ShiftMask,	 	       XK_s,        spawn,	    SHCMD("maim -s | xclip -selection clipboard -t image/png && notify-send '📋 Screenshot area copied to clipboard'") },

  // { MODKEY|ShiftMask, XK_i,   spawn, SHCMD("xdotool type $(grep -v '^#' $HOME/.local/share/bookmarks | dmenu -i -l 50 | cut -d' ' -f1)")},
  // { MODKEY|ShiftMask, XK_b,   spawn, SHCMD(TERMINAL " -e $EDITOR $HOME/.local/share/bookmarks")},
  // { MODKEY|ControlMask, XK_b,   spawn, SHCMD(TERMINAL "bm-append")},

  // see 'bmks help'
  // sc: https://tools.suckless.org/dmenu/scripts/
  { MODKEY|ShiftMask,   XK_i,   spawn, SHCMD("bmks")}, // select urls
  { MODKEY|ControlMask, XK_i,   spawn, SHCMD("bmks del")}, // delete urls
  { MODKEY|ShiftMask, XK_b,   spawn, SHCMD(TERMINAL " -e $EDITOR $HOME/.bmks/urls")}, // open urls

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
  { ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
  { ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
  { ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
  { ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
  { ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
  { ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
  /* placemouse options, choose which feels more natural:
   *    0 - tiled position is relative to mouse cursor
   *    1 - tiled postiion is relative to window center
   *    2 - mouse pointer warps to window center
   *
   * The moveorplace uses movemouse or placemouse depending on the floating state
   * of the selected client. Set up individual keybindings for the two if you want
   * to control these separately (i.e. to retain the feature to move a tiled window
   * into a floating position).
   */
  { ClkClientWin,         MODKEY,         Button1,        moveorplace,    {.i = 1} },
  { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
  { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|ShiftMask, Button1,      dragmfact,      {0} },
	{ ClkClientWin,         MODKEY|ShiftMask, Button3,      dragcfact,      {0} },
  { ClkTagBar,            0,              Button1,        view,           {0} },
  { ClkTagBar,            0,              Button3,        toggleview,     {0} },
  { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
  { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

