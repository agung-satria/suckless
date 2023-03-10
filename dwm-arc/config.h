/* See LICENSE file for copyright and license details. */
#define XF86MonBrightnessDown 0x1008ff03
#define XF86MonBrightnessUp 0x1008ff02
#define TERMINAL "st"
#define TERMCLASS "St"

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 2;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static int showsystray        = 0;     /* 0 means no systray */
// no gap
// static const unsigned int gappih    = 0;       /* horiz inner gap between windows */
// static const unsigned int gappiv    = 0;       /* vert inner gap between windows */
// static const unsigned int gappoh    = 0;       /* horiz outer gap between windows and screen edge */
// static const unsigned int gappov    = 0;       /* vert outer gap between windows and screen edge */
// dekat
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 14;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 20;       /* vert outer gap between windows and screen edge */
// agak jauh
// static const unsigned int gappih    = 16;       /* horiz inner gap between windows */
// static const unsigned int gappiv    = 16;       /* vert inner gap between windows */
// static const unsigned int gappoh    = 22;       /* horiz outer gap between windows and screen edge */
// static const unsigned int gappov    = 30;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;     /* 0 means no bar */
static const int topbar             = 1;     /* 0 means bottom bar */
/*  Display modes of the tab bar: never shown, always shown, shown only in  */
/*  monocle mode in the presence of several windows.                        */
/*  Modes after showtab_nmodes are disabled.                                */
enum showtab_modes { showtab_never, showtab_auto, showtab_nmodes, showtab_always};
static const int showtab			= showtab_auto;        /* Default tab bar show mode */
static const int toptab				= False;               /* False means bottom tab bar */

static const char *fonts[]        = {"SF Pro Display:weight=Medium:size=14:antialias=true:autohint=true",
  "JetBrainsMono Nerd Font:style:medium:size=14:autohint=true",
  "JoyPixels:size=12:antialias=true:autohint=true",
  "Noto Color Emoji:pixelsize=14:antialias=true:autohint=true",
  "Font Awesome 6 Brands Regular:pixelsize=14:antialias=true:autohint=true",
  "Font Awesome 6 Free Regular:pixelsize=14:antialias=true:autohint=true",
  "Font Awesome 6 Free Solid:pixelsize=14:antialias=true:autohint=true",
  "Material:size=14:autohint=true"};
static const char dmenufont[]     = "SF Pro Display:weight=Medium:size=14:antialias=true:autohint=true";

// // pop color^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
static const char col_gray1[]     = "#171a1f";
static const char col_gray2[]     = "#384148";
static const char col_gray3[]     = "#bbbbbb";
static const char col_gray4[]     = "#fafdff";
static const char col_hl   []     = "#313131";
static const char col_pop[]       = "#74bee9";
static const char col_red[]       = "#e05f65";
static const char *colors[][3]    = {
    /*               fg         bg         border   */
    [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
    [SchemeSel]  = { col_pop, col_gray2,  col_pop  },
    [SchemeTitle]  = { col_gray4, col_gray1,  col_hl  },
};
// // also change the dmenu color below below
// // pop color_________________________________________

typedef struct {
    const char *name;
    const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "100x25", NULL };
const char *spcmd2[] = {"st", "-n", "spcalc", "-g", "31x17", "bc", "-lq", NULL };
const char *spcmd3[] = {"st", "-n", "spncmpcpp", "-g", "100x25", "-e", "ncmpcpp", NULL };
const char *spcmd4[] = {"st", "-n", "spcalcurse", "-g", "100x25", "-e", "calcurse", NULL };
const char *spcmd5[] = {"st", "-n", "spnmtui", "-g", "100x25", "-e", "nmtui", NULL };
const char *spcmd6[] = {"st", "-n", "spranger", "-g", "100x25", "-e", "ranger", NULL };
const char *spcmd7[] = {"st", "-n", "splf", "-g", "100x25", "-e", "lfub", NULL };
static Sp scratchpads[] = {

    /* name          cmd  */
    {"spterm",      spcmd1},
    {"spcalc",      spcmd2},
    {"spncmpcpp",   spcmd3},
    {"spcalcurse",  spcmd4},
    {"spnmtui",     spcmd5},
    {"spranger",    spcmd6},
    {"splf",        spcmd7},

};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
// static const char *tags[] = { "1: ???", "2: ???", "3: ???", "4: ???", "5: ???", "6: ???", "7: ???", "8: ???", "9: ???" };
// static const char *tags[] = { "???", "???", "???", "???", "???", "???", "???", "???", "???" };
// static const char *tags[] = { "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
    */
    /* class                  instance  title      tags mask    isfloating   monitor */
    { "Brave-browser",        NULL,		  NULL,		   1 << 1,	    0,		       -1 },
    { "Google-chrome",        NULL,		  NULL,		   1 << 1,	    0,		       -1 },
    { "firefox",              NULL,		  NULL,		   1 << 1,	    0,		       -1 },
    { "Code",                 NULL,		  NULL,		   1 << 2,	    0,		       -1 },
    { "code",                 NULL,		  NULL,		   1 << 2,	    0,		       -1 },
    { "libreoffice",	        NULL,		  NULL,		   1 << 2,	    0,     	     -1 },
    { "TelegramDesktop",      NULL,		  NULL,		   1 << 3,	    0,		       -1 },
    { "Shotcut",	            NULL,		  NULL,		   1 << 4,	    0,		       -1 },
    { "Gimp",	                NULL,		  NULL,		   1 << 5,	    0,		       -1 },
    { "Inkscape",	            NULL,		  NULL,		   1 << 6,	    0,		       -1 },
    { "obs",	                NULL,		  NULL,		   1 << 7,	    0,		       -1 },
    { "vokoscreen",           NULL,     NULL,      0,           1,           -1 },
    { "vokoscreenNG",         NULL,     NULL,      0,           1,           -1 },
    { "SimpleScreenRecorder", NULL,     NULL,      0,           1,           -1 },
    { "Yad",			            NULL,     NULL,      0,           1,           -1 },
    { "yad",			            NULL,     NULL,      0,           1,           -1 },
    { "Lxappearance",		      NULL,     NULL,      0,           1,           -1 },
    { "lxappearance",		      NULL,     NULL,      0,           1,           -1 },
    { "vCoolor",			        NULL,     NULL,      0,           1,           -1 },
    { "winbox64.exe",	        NULL,     NULL,      0,           1,           -1 },
    { "Wine",                 NULL,     NULL,      0,           1,           -1 },
    { "Eog",                  NULL,     NULL,      0,           1,           -1 },
    { "Arandr",               NULL,     NULL,      0,           1,           -1 },
    { "ksnip",                NULL,     NULL,      0,           1,           -1 },
    { "Pavucontrol",          NULL,     NULL,      0,           1,           -1 },
    { "xdman-Main",           NULL,     NULL,      0,           1,           -1 },
    { "arandr",               NULL,     NULL,      0,           1,           -1 },
    { "Sxiv",                 NULL,     NULL,      0,           1,           -1 },
    { "Mirage",               NULL,     NULL,      0,           1,           -1 },
    { "Viewnior",             NULL,     NULL,      0,           1,           -1 },
    { "Nemo",                 NULL,     NULL,      0,           1,           -1 },
    { "File-roller",          NULL,     NULL,      0,           1,           -1 },
    { "Org.gnome.Nautilus",   NULL,     NULL,      0,           1,           -1 },
    { "org.gnome.Nautilus",   NULL,     NULL,      0,           1,           -1 },
    { "dolphin",              NULL,     NULL,      0,           1,           -1 },
    { "Gnome-calculator",     NULL,     NULL,      0,           1,           -1 },
    { "Gnome-calendar",       NULL,     NULL,      0,           1,           -1 },
    { "Galculator",           NULL,     NULL,      0,           1,           -1 },
    { "audacious",            NULL,     NULL,      0,           0,           -1 },
    { "Dragon",               NULL,     NULL,      0,           1,           -1 },
    /* scratchpads */
    { NULL,		          "spterm",		    NULL,		   SPTAG(0),	  1,           -1 },
    { NULL,		          "spcalc",		    NULL,		   SPTAG(1),	  1,           -1 },
    { NULL,		          "spncmpcpp",    NULL,		   SPTAG(2),	  1,           -1 },
    { NULL,		          "spcalcurse",   NULL,	     SPTAG(3),	  1,           -1 },
    { NULL,		          "spnmtui",      NULL,		   SPTAG(4),	  1,           -1 },
    { NULL,		          "spranger",     NULL,		   SPTAG(5),	  1,           -1 },
    { NULL,		          "splf",         NULL,		   SPTAG(6),	  1,           -1 },
    /* floatthings */
    { "float-st",             NULL,     NULL,      0,           1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.57; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
    /* symbol     arrange function */

    //  /*0*/ { "[]=",      tile },    /* first entry is default */
    //  /*1*/ { "TTT",      bstack },
    //  /*2*/ { "[M]",      monocle },
    //  /*3*/ { "[@]",      spiral },
    //  /*4*/ { "[\\]",     dwindle },
    //  /*5*/ { "H[]",      deck },
    //  /*6*/ { "===",      bstackhoriz },
    //  /*7*/ { "HHH",      grid },
    //  /*8*/ { "###",      nrowgrid },
    //  /*9*/ { "---",      horizgrid },
    //  /*10*/{ ":::",      gaplessgrid },
    //  /*11*/{ "|M|",      centeredmaster },
    //  /*12*/{ ">M>",      centeredfloatingmaster },
    //  /*13*/{ "><>",      NULL },    /* no layout function means floating behavior */

    /*0*/ { "???",      tile },    /* first entry is default */
    /*1*/ { "???",      bstack },
    /*2*/ { "???",      monocle },
    /*3*/ { "???",      spiral },
    /*4*/ { "???",      dwindle },
    /*5*/ { "???",      deck },
    /*6*/ { "???",      bstackhoriz },
    /*7*/ { "???",      grid },
    /*8*/ { "???",      nrowgrid },
    /*9*/ { "???",      horizgrid },
    /*10*/{ "???",      gaplessgrid },
    /*11*/{ "???",      centeredmaster },
    /*12*/{ "???",      centeredfloatingmaster },
    /*13*/{ "???",     NULL },    /* no layout function means floating behavior */

    { NULL,           NULL },
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
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */

// //agstr dmenu color^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_hl, "-sf", col_gray1, NULL };
// //agstr dmenu color______________________________________________

// pop dmenu color^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_hl, "-sf", col_pop, NULL };
// pop dmenu color_______________________________________________

static const char *termcmd[]  = { "st", NULL };
// static const char *termcmd[]  = { "alacritty", NULL };

#include <X11/XF86keysym.h>
#include "movestack.c"
#include "shiftview.c"
#include "nextprevtag.c"

static Key keys[] = {
    /* modifier                     key        function        argument */
    /*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^agstr^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */

  /* volume and brightness */
    { 0,  XF86XK_AudioMute,           spawn, SHCMD("changevolume mute; pkill -RTMIN+1 dwmblocks") },
    { 0,  XF86XK_AudioRaiseVolume,    spawn, SHCMD("changevolume up; pkill -RTMIN+1 dwmblocks") },
    { 0,  XF86XK_AudioLowerVolume,    spawn, SHCMD("changevolume down; pkill -RTMIN+1 dwmblocks") },
    { 0,  XF86MonBrightnessUp,        spawn, SHCMD("changebrightness up; pkill -RTMIN+2 dwmblocks") },
    { 0,  XF86MonBrightnessDown,      spawn, SHCMD("changebrightness down; pkill -RTMIN+2 dwmblocks") },
    { MODKEY,			        XK_0,		    spawn, SHCMD("changevolume mute; pkill -RTMIN+1 dwmblocks") },
    { MODKEY,			        XK_equal,		spawn, SHCMD("changevolume up; pkill -RTMIN+1 dwmblocks") },
    { MODKEY,			        XK_minus,		spawn, SHCMD("changevolume down; pkill -RTMIN+1 dwmblocks") },
    { MODKEY|ShiftMask,		XK_equal,		spawn, SHCMD("changebrightness up; pkill -RTMIN+2 dwmblocks") },
    { MODKEY|ShiftMask,		XK_minus,		spawn, SHCMD("changebrightness down; pkill -RTMIN+2 dwmblocks") },

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

    /* launch (apps, dmenu script, etc) */
    { MODKEY|ShiftMask,		    XK_BackSpace,     	spawn,		SHCMD("systemctl suspend && lockwithsound") },
    { MODKEY,				    XK_r,             spawn,		SHCMD("rofi modi drun -show drun show-icons true -columns 2 width 45") },
    // { MODKEY,            		XK_w,             spawn,		SHCMD("brave") },
    // { MODKEY|ShiftMask,  		XK_w,             spawn,		SHCMD("brave --incognito") },
    { MODKEY,            		XK_w,             spawn,		SHCMD("firefox") },
    { MODKEY|ShiftMask,  		XK_w,             spawn,		SHCMD("firefox --private-window") },
    { MODKEY,				    XK_Escape,        spawn,		SHCMD("sysact") },
    { MODKEY,				    XK_BackSpace,     spawn,		SHCMD("sysact") },
    { MODKEY,                   XK_a,             spawn,		SHCMD("/home/agung/.config/eww/dashboard/launch_dashboard") },
    { MODKEY,                   XK_s,             spawn,		SHCMD("/home/agung/.config/eww/slider/launch_slider") },
    { MODKEY,                   XK_m,             spawn,		SHCMD("/home/agung/.config/eww/music/launch_music") },
    // { MODKEY,                   XK_Escape,        spawn,		SHCMD("/home/agung/.config/eww/powermenu/launch_powermenu") },
    { MODKEY|ShiftMask,  		XK_d,             spawn,		SHCMD("samedir") },
    { MODKEY,  		            XK_y,             spawn,		SHCMD("xcpcolor") },
    { MODKEY|ControlMask,  	    XK_e,             spawn,		SHCMD("nemo") },
    { MODKEY|ShiftMask,		    XK_apostrophe,    spawn,	    SHCMD("galculator") },
    { MODKEY,		           	XK_p,	  	  spawn,	    	SHCMD("arandr") },
    { MODKEY|ShiftMask,		    XK_a,   	  spawn,	    	SHCMD("dunstctl history-pop") },
    { MODKEY|ControlMask,	    XK_a,   	  spawn,	    	SHCMD("dunstctl close-all") },
    // { MODKEY|ControlMask,		XK_a,   	  spawn,	    	SHCMD("dunstctl close") },
    { MODKEY|ControlMask,		XK_l,   	  spawn,	    	SHCMD("lockwithsound") }, //betterlockscreen
    { MODKEY|ALTKEY,		    XK_l,   	  spawn,	    	SHCMD("lock") }, //scrot transparent lock

    // floatthings
    { MODKEY|ShiftMask,         	XK_r,             spawn,        SHCMD("st -c float-st -g 100x25 gotop") },
    { MODKEY,			        XK_F4,		      spawn,		SHCMD(TERMINAL " -c float-st -g 100x25 pulsemixer") },
    { MODKEY,			       XK_F11,		spawn,		SHCMD("mpv --untimed --no-cache --no-osc --no-input-default-bindings --profile=low-latency --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },

    /* screenshots */
    { 0,			       XK_Print,	spawn,		SHCMD("ss-full") },
    { ShiftMask,	       	       XK_Print,	spawn,		SHCMD("maimpick") },
    { ControlMask,         	       XK_Print,	spawn,		SHCMD("ss-cp") },
    { MODKEY,	           	       XK_v,        spawn,	    SHCMD("dmenurecord") },
    { MODKEY|ShiftMask,	         XK_v,        spawn,	    SHCMD("simplescreenrecorder") },
    { MODKEY,	           	       XK_grave,    spawn,	    SHCMD("dmenuunicode") },
    { MODKEY|ShiftMask,	 	       XK_s,        spawn,	    SHCMD("maim -s | xclip -selection clipboard -t image/png") },

    /*___________________________________________________agstr____________________________________________________ */

    { MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
    { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
    { MODKEY|ALTKEY,                XK_Return, spawn,          SHCMD("tabbed -r 2 st -w ''") }, //open tabbed in st
    { MODKEY|ControlMask,           XK_Return, spawn,          SHCMD("st -e runtmux") }, //attach tmux session, if attached, create new
    { MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY|ShiftMask,             XK_b,      togglesystray,  {0} },
    { MODKEY|ControlMask,           XK_w,      tabmode,        {-1} },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
    { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
    { ALTKEY,                       XK_Tab,    swapfocus,      {0} },
    { MODKEY,                       XK_n,      incnmaster,     {.i = +1 } },
    { MODKEY|ShiftMask,             XK_n,      incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.035} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.035} },
    { MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = +0.25} },
    { MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = -0.25} },
    { MODKEY|ShiftMask,             XK_g,      setcfact,       {.f =  0.00} },

    { MODKEY,                       XK_space,  zoom,           {0} },
    { MODKEY,                       XK_x,      togglegaps,     {0} },
    { MODKEY|ShiftMask,             XK_x,      defaultgaps,    {0} },
    { MODKEY,                       XK_z,      incrgaps,       {.i = +3 } },
    { MODKEY|ShiftMask,             XK_z,      incrgaps,       {.i = -3 } },
    { MODKEY|ControlMask,           XK_i,      incrigaps,      {.i = +3 } },
    { MODKEY|ControlMask|ShiftMask, XK_i,      incrigaps,      {.i = -3 } },
    { MODKEY|ControlMask,           XK_o,      incrogaps,      {.i = +3 } },
    { MODKEY|ControlMask|ShiftMask, XK_o,      incrogaps,      {.i = -3 } },
    { MODKEY|ALTKEY,                XK_6,      incrihgaps,     {.i = +3 } },
    { MODKEY|ALTKEY|ShiftMask,      XK_6,      incrihgaps,     {.i = -3 } },
    { MODKEY|ALTKEY,                XK_7,      incrivgaps,     {.i = +3 } },
    { MODKEY|ALTKEY|ShiftMask,      XK_7,      incrivgaps,     {.i = -3 } },
    { MODKEY|ALTKEY,                XK_8,      incrohgaps,     {.i = +3 } },
    { MODKEY|ALTKEY|ShiftMask,      XK_8,      incrohgaps,     {.i = -3 } },
    { MODKEY|ALTKEY,                XK_9,      incrovgaps,     {.i = +3 } },
    { MODKEY|ALTKEY|ShiftMask,      XK_9,      incrovgaps,     {.i = -3 } },

    { MODKEY|ShiftMask,             XK_i,      view_adjacent,  { .i = -1 } },
    { MODKEY|ShiftMask,             XK_o,      view_adjacent,  { .i = +1 } },
    { MODKEY,			                  XK_i,	     shiftview,	     { .i = -1 } },
    { MODKEY,			                  XK_o,	     shiftview,	     { .i = 1 } },

    { MODKEY,                       XK_Tab,    view,           {0} },
    { MODKEY,                       XK_q,      killclient,     {0} },
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY|ControlMask,           XK_t,      setlayout,      {.v = &layouts[1]} },
    { MODKEY|ControlMask,           XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY|ControlMask,           XK_s,      setlayout,      {.v = &layouts[3]} },
    { MODKEY|ControlMask,           XK_c,      setlayout,      {.v = &layouts[5]} },
    { MODKEY|ControlMask,           XK_g,      setlayout,      {.v = &layouts[10]} },
    { MODKEY|ControlMask,           XK_u,      setlayout,      {.v = &layouts[11]} },
    { MODKEY|ControlMask,           XK_f,      setlayout,      {.v = &layouts[13]} },
    { MODKEY|ControlMask,	          XK_comma,  cyclelayout,    {.i = -1 } },
    { MODKEY|ControlMask,           XK_period, cyclelayout,    {.i = +1 } },
    { MODKEY,                       XK_semicolon,setlayout,    {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY,                       XK_f,      togglefullscr,  {0} },
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
    { MODKEY|ShiftMask,             XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ControlMask,           XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ControlMask,           XK_minus,  setborderpx,    {.i = -1 } },
    { MODKEY|ControlMask,           XK_equal,  setborderpx,    {.i = +1 } },
    { MODKEY|ControlMask|ShiftMask, XK_equal,  setborderpx,    {.i = 0 } },
    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

    // scratchpad
    { MODKEY|ShiftMask, 	          XK_Return, togglescratch,  {.ui = 0 } },
    { MODKEY,          	            XK_apostrophe, togglescratch,  {.ui = 1 } },
    { MODKEY|ShiftMask,    	        XK_m,	   togglescratch,  {.ui = 2 } },
    { MODKEY,    	                  XK_c,	   togglescratch,  {.ui = 3 } },
    { MODKEY|ControlMask,           XK_n,	   togglescratch,  {.ui = 4 } },
    { MODKEY|ShiftMask,             XK_e,	   togglescratch,  {.ui = 5 } },
    { MODKEY,                       XK_e,	   togglescratch,  {.ui = 6 } },

    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    { MODKEY|ControlMask,           XK_q,      quit,           {1} }, //reload dwm
    { MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {0} }, //quit dwm
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask    button       function        argument */
    { ClkTagBar,            MODKEY,       Button1,     tag,            {0} },
    { ClkTagBar,            MODKEY,       Button3,     toggletag,      {0} },
    { ClkWinTitle,          0,            Button2,     zoom,           {0} },
    { ClkStatusText,        0,            Button1,     sigdwmblocks,   {.i = 1} },
    { ClkStatusText,        0,            Button2,     sigdwmblocks,   {.i = 2} },
    { ClkStatusText,        0,            Button3,     sigdwmblocks,   {.i = 3} },
    { ClkStatusText,        0,            Button4,     sigdwmblocks,   {.i = 4} },
    { ClkStatusText,        0,            Button5,     sigdwmblocks,   {.i = 5} },
    { ClkStatusText,        ShiftMask,    Button1,     sigdwmblocks,   {.i = 6} },


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
    { ClkClientWin,		      MODKEY,		      Button4,	      incrgaps,	{.i = +3} },
    { ClkClientWin,		      MODKEY,		      Button5,	      incrgaps,	{.i = -3} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
    { ClkTabBar,            0,              Button1,        focuswin,       {0} },
};
