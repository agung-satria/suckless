/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
    "SF Pro Display:weight=Medium:size=14:antialias=true:autohint=true",
    "JetBrainsMono Nerd Font:style:medium:size=14",
    "Noto Color Emoji:pixelsize=16:antialias=true:autohint=true"
};
static const unsigned int bgalpha = 0xe0;
static const unsigned int fgalpha = OPAQUE;
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {

// //pop color---------------------------------------
	/*     fg         bg       */
	[SchemeNorm] = { "#b6beca", "#171a1f" },
	[SchemeSel] = { "#74bee9", "#39393c" },
	[SchemeOut] = { "#090909", "#90daff" },
};
// //pop color---------------------------------------

static const unsigned int alphas[SchemeLast][2] = {
	/*		fgalpha		bgalphga	*/
	[SchemeNorm] = { fgalpha, bgalpha },
	[SchemeSel] = { fgalpha, bgalpha },
	[SchemeOut] = { fgalpha, bgalpha },
};

/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
