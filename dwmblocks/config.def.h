//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"",   "sd-volarch",	        0,		          1},
	{"",   "sd-battery",	          5,		        3},
	{"",   "sd-nettraf",           5,		      2},
	{"",   "sd-pacpackages",	      5,		      7},
	{"",   "sd-internet",	          5,		      22},
  {"",   "sd-clock",	            60,		      10},

};
static char *delim = " ";
