//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"",   "sb-fakesystray",	          0,		4},
//	{"",   "sb-discord",	          0,		28},
//	{"",   "sb-emojipicker",	       0,		25},
	{"",   "sb-mpdicon2",	       1,		26},
	{"",   "sb-screenshot",	       0,		17},
//	{"",   "sb-screenrecord",	       0,		24},
	{"",   "sb-diskusage2",	        0,		8},
	{"",   "sb-battery2",	          5,		3},
	{"",   "sb-internet2",	            3,		22},
	{"",   "sb-volarch3",	        0,		1},
	{"",   "sb-search",	        0,		12},
	{"",   "sb-ewwslider",	        0,		7},
	{"",   "sb-clock2",	            60,		10},
//	{"",   "sb-notification",	            0,		14},
//	{"",   "sb-showdesktop",	            0,		19},

};

//Sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char *delim = " ";

// Have dwmblocks automatically recompile and run when you edit this file in
// vim with the following line in your vimrc/init.vim:

// autocmd BufWritePost ~/.local/src/dwmblocks/config.h !cd ~/.local/src/dwmblocks/; sudo make install && { killall -q dwmblocks;setsid dwmblocks & }
