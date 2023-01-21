/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048
static const struct arg args[] = {
	/* function format          argument */
  	{ run_command,	"^c#e5d8ea^ %6s", "sb-clock2" },
	{ run_command,	"^c#98C379^ %2s", "sb-battery3" },
//	{ run_command,	"^c#B0B2BE^ %1s ", "sb-mpdsong" },
//	{ run_command,	"^c#D19A66^ %2s ", "sb-nettraf" },
//	{ run_command,	"^c#61AFEF^ %1s ", "sb-volarch2" },
//	{ run_command,	"^c#D5C849^ %2s ", "sb-brightperc" },
//	{ run_command,	"^c#e5d8ea^ %2s ", "sb-memory" },
//	{ run_command,	"^c#e5d8ea^ %2s ", "sb-diskusage" },
//	{ run_command,	"^c#56B6C2^ %2s ", "sb-clock" },
//  	{ run_command,	"^c#e5d8ea^ %2s ", "sb-dwmlogo4px" },
};
