#pragma once

enum MicrosoftDiskFileOperatorFlag
{
	file_error_pending = 16,
	file_dont_truncate = 8,
	file_unknown = 4,
	file_info_loaded = 2,
	file_read_only = 1
};