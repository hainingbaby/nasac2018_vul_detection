#include <stdio.h>
#include "zonemeta.h"
#include "unistr.h"

int main()
{
	UnicodeString us;
	ZoneMeta meta;
	meta.getMetazoneMappings(us);
}