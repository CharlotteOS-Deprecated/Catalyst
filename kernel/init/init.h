enum init_status {
	INIT_SUCCESS = 0,
	INIT_FAILURE = 1,
	INIT_HALT = 2,
};

enum init_status ct_init();
enum init_status ct_deinit();
