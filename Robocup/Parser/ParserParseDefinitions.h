/************************************************************
 * Student Name:     Maxim Vainshtein                       *
 * Exercise Name:    Ex3                                    *
 * File description: Declaration of Parser Parse definitions*
 ***********************************************************/

#ifndef Ex3_ParserParseDefinitions_h
#define Ex3_ParserParseDefinitions_h

#define PARSER_KEYWORD_WARNING "warning"
#define PARSER_KEYWORD_ERROR "error"
#define PARSER_KEYWORD_SERVER_PARAMETERS "server_param"
#define PARSER_KEYWORD_INIT "init"
#define PARSER_KEYWORD_PLAYER_PARAM "player_param"

#define PARSER_KEYWORD_AUDIO_CUT_DISTANCE "audio_cut_dist"
#define PARSER_KEYWORD_AUTO_MODE "auto_mode"
#define PARSER_KEYWORD_BACK_DASH_RATE "back_dash_rate"
#define PARSER_KEYWORD_BACK_PASSES "back_passes"
#define PARSER_KEYWORD_BALL_ACCELERATION_MAX "ball_accel_max"
#define PARSER_KEYWORD_BALL_DECAY "ball_decay"
#define PARSER_KEYWORD_BALL_RANDOM "ball_rand"
#define PARSER_KEYWORD_BALL_SIZE "ball_size"
#define PARSER_KEYWORD_BALL_SPEED_MAX "ball_speed_max"
#define PARSER_KEYWORD_BALL_STUCK_AREA "ball_stuck_area"
#define PARSER_KEYWORD_BALL_WEIGHT "ball_weight"
#define PARSER_KEYWORD_CATCH_BAN_CYCLE "catch_ban_cycle"
#define PARSER_KEYWORD_CATCH_PROBABILITY "catch_probability"
#define PARSER_KEYWORD_CATCHABLE_AREA_L "catchable_area_l"
#define PARSER_KEYWORD_CATCHABLE_AREA_W "catchable_area_w"
#define PARSER_KEYWORD_CKICK_MARGIN "ckick_margin"
#define PARSER_KEYWORD_CLANG_ADVICE_WIN "clang_advice_win"
#define PARSER_KEYWORD_CLANG_DEFINE_WIN "clang_define_win"
#define PARSER_KEYWORD_CLANG_DEL_WIN "clang_del_win"
#define PARSER_KEYWORD_CLANG_INFO_WIN "clang_info_win"
#define PARSER_KEYWORD_CLANG_MESS_DELAY "clang_mess_delay"
#define PARSER_KEYWORD_CLANG_MESS_PER_CYCLE "clang_mess_per_cycle"
#define PARSER_KEYWORD_CLANG_META_WIN "clang_meta_win"
#define PARSER_KEYWORD_CLANG_RULE_WIN "clang_rule_win"
#define PARSER_KEYWORD_CLANG_WIN_SIZE "clang_win_size"
#define PARSER_KEYWORD_COACH "coach"
#define PARSER_KEYWORD_COACH_PORT "coach_port"
#define PARSER_KEYWORD_COACH_WITH_REFEREE "coach_w_referee"
#define PARSER_KEYWORD_CONNECT_WAIT "connect_wait"
#define PARSER_KEYWORD_CONTROL_RADIUS "control_radius"
#define PARSER_KEYWORD_DASH_ANGLE_STEP "dash_angle_step"
#define PARSER_KEYWORD_DASH_POWER_RATE "dash_power_rate"
#define PARSER_KEYWORD_DROP_BALL_TIME "drop_ball_time"
#define PARSER_KEYWORD_EFFORT_DECAY "effort_dec"
#define PARSER_KEYWORD_EFFORT_DECAY_THR "effort_dec_thr"
#define PARSER_KEYWORD_EFFORT_INCREASE "effort_inc"
#define PARSER_KEYWORD_EFFORT_INCREASE_THR "effort_inc_thr"
#define PARSER_KEYWORD_EFFORT_INIT "effort_init"
#define PARSER_KEYWORD_EFFORT_MIN "effort_min"
#define PARSER_KEYWORD_EFFORT_MAX "effort_max"
#define PARSER_KEYWORD_EXTRA_HALF_TIME "extra_half_time"
#define PARSER_KEYWORD_EXTRA_STAMINA "extra_stamina"
#define PARSER_KEYWORD_FORBID_KICKOFF_OFFSIDE "forbid_kick_off_offside"
#define PARSER_KEYWORD_FOUL_CYCLES "foul_cycles"
#define PARSER_KEYWORD_FOUL_DETECT_PROBABILITY "foul_detect_probability"
#define PARSER_KEYWORD_FOUL_EXPONENT "foul_exponent"
#define PARSER_KEYWORD_FREE_KICK_FAULTS "free_kick_faults"
#define PARSER_KEYWORD_FREEFORM_SEND_PERIOD "freeform_send_period"
#define PARSER_KEYWORD_FREEFORM_WAIT_PERIOD "freeform_wait_period"
#define PARSER_KEYWORD_FULL_STATE_L "fullstate_l"
#define PARSER_KEYWORD_FULL_STATE_R "fullstate_r"
#define PARSER_KEYWORD_GAME_LOG_COMPRESSION "game_log_compression"
#define PARSER_KEYWORD_GAME_LOG_DATED "game_log_dated"
#define PARSER_KEYWORD_GAME_LOG_DIRECTORY "game_log_dir"
#define PARSER_KEYWORD_GAME_LOG_FIXED "game_log_fixed"
#define PARSER_KEYWORD_GAME_LOG_FIXED_NAME "game_log_fixed_name"
#define PARSER_KEYWORD_GAME_LOG_VERSION "game_log_version"
#define PARSER_KEYWORD_GAME_LOGGING "game_logging"
#define PARSER_KEYWORD_GAME_OVER_WAIT "game_over_wait"
#define PARSER_KEYWORD_GOAL_WIDTH "goal_width"
#define PARSER_KEYWORD_GOALIE_MAX_MOVES "goalie_max_moves"
#define PARSER_KEYWORD_GOLDEN_GOAL "golden_goal"
#define PARSER_KEYWORD_HALF_TIME "half_time"
#define PARSER_KEYWORD_HEAR_DECAY "hear_decay"
#define PARSER_KEYWORD_HEAR_INC "hear_inc"
#define PARSER_KEYWORD_HEAR_MAX "hear_max"
#define PARSER_KEYWORD_INERTIA_MOMENT "inertia_moment"
#define PARSER_KEYWORD_KEEP_AWAY "keepaway"
#define PARSER_KEYWORD_KEEP_AWAY_LENGTH "keepaway_length"
#define PARSER_KEYWORD_KEEP_AWAY_LOG_DATED "keepaway_log_dated"
#define PARSER_KEYWORD_KEEP_AWAY_LOG_DIR "keepaway_log_dir"
#define PARSER_KEYWORD_KEEP_AWAY_LOG_FIXED "keepaway_log_fixed"
#define PARSER_KEYWORD_KEEP_AWAY_LOG_FIXED_NAME "keepaway_log_fixed_name"
#define PARSER_KEYWORD_KEEP_AWAY_LOGGING "keepaway_logging"
#define PARSER_KEYWORD_KEEP_AWAY_START "keepaway_start"
#define PARSER_KEYWORD_KEEP_AWAY_WIDTH "keepaway_width"
#define PARSER_KEYWORD_KICKOFF_WAIT "kick_off_wait"
#define PARSER_KEYWORD_KICK_POWER_RATE "kick_power_rate"
#define PARSER_KEYWORD_KICK_RAND "kick_rand"
#define PARSER_KEYWORD_KICK_RAND_FACTOR_L "kick_rand_factor_l"
#define PARSER_KEYWORD_KICK_RAND_FACTOR_R "kick_rand_factor_r"
#define PARSER_KEYWORD_KICKABLE_MARGIN "kickable_margin"
#define PARSER_KEYWORD_LANDMARK_FILE "landmark_file"
#define PARSER_KEYWORD_LOG_DATE_FORMAT "log_date_format"
#define PARSER_KEYWORD_LOG_TIMES "log_times"
#define PARSER_KEYWORD_MAX_BACK_TACKLE_POWER "max_back_tackle_power"
#define PARSER_KEYWORD_MAX_DASH_ANGLE "max_dash_angle"
#define PARSER_KEYWORD_MAX_DASH_POWER "max_dash_power"
#define PARSER_KEYWORD_MAX_GOAL_KICKS "max_goal_kicks"
#define PARSER_KEYWORD_MAX_TACKLE_POWER "max_tackle_power"
#define PARSER_KEYWORD_MAX_MOMENT "maxmoment"
#define PARSER_KEYWORD_MAX_NECK_ANGLE "maxneckang"
#define PARSER_KEYWORD_MAX_NECK_MOMENT "maxneckmoment"
#define PARSER_KEYWORD_MAX_POWER "maxpower"
#define PARSER_KEYWORD_MIN_DASH_ANGLE "min_dash_angle"
#define PARSER_KEYWORD_MIN_DASH_POWER "min_dash_power"
#define PARSER_KEYWORD_MIN_MOMENT "minmoment"
#define PARSER_KEYWORD_MIN_NECK_ANGLE "minneckang"
#define PARSER_KEYWORD_MIN_NECK_MOMENT "minneckmoment"
#define PARSER_KEYWORD_MIN_POWER "minpower"
#define PARSER_KEYWORD_NR_EXTRA_HALFS "nr_extra_halfs"
#define PARSER_KEYWORD_NR_NORMAL_HALFS "nr_normal_halfs"
#define PARSER_KEYWORD_OFFSIDE_ACTIVE_AREA_SIZE "offside_active_area_size"
#define PARSER_KEYWORD_OFFSIDE_KICK_MARGIN "offside_kick_margin"
#define PARSER_KEYWORD_OL_COACH_PORT "olcoach_port"
#define PARSER_KEYWORD_OLD_COACH_HEAR "old_coach_hear"
#define PARSER_KEYWORD_PEN_ALLOW_MULTIPLE_KICKS "pen_allow_mult_kicks"
#define PARSER_KEYWORD_PEN_BEFORE_SETUP_WAIT "pen_before_setup_wait"
#define PARSER_KEYWORD_PEN_COACH_MOVES_PLAYERS "pen_coach_moves_players"
#define PARSER_KEYWORD_PEN_DISTANCE_X "pen_dist_x"
#define PARSER_KEYWORD_PEN_MAX_EXTRA_KICKS "pen_max_extra_kicks"
#define PARSER_KEYWORD_PEN_MAX_GOALIE_DISTANCE_X "pen_max_goalie_dist_x"
#define PARSER_KEYWORD_PEN_NR_KICKS "pen_nr_kicks"
#define PARSER_KEYWORD_PEN_RANDOM_WINNER "pen_random_winner"
#define PARSER_KEYWORD_PEN_READY_WAIT "pen_ready_wait"
#define PARSER_KEYWORD_PEN_SETUP_WAIT "pen_setup_wait"
#define PARSER_KEYWORD_PEN_TAKEN_WAIT "pen_taken_wait"
#define PARSER_KEYWORD_PENALTY_SHOOT_OUTS "penalty_shoot_outs"
#define PARSER_KEYWORD_PLAYER_ACCELERATION_MAX "player_accel_max"
#define PARSER_KEYWORD_PLAYER_DECAY "player_decay"
#define PARSER_KEYWORD_PLAYER_RAND "player_rand"
#define PARSER_KEYWORD_PLAYER_SIZE "player_size"
#define PARSER_KEYWORD_PLAYER_SPEED_MAX "player_speed_max"
#define PARSER_KEYWORD_PLAYER_SPEED_MAX_MIN "player_speed_max_min"
#define PARSER_KEYWORD_PLAYER_WEIGHT "player_weight"
#define PARSER_KEYWORD_POINTS_TO_BAN "point_to_ban"
#define PARSER_KEYWORD_POINTS_TO_DURATION "point_to_duration"
#define PARSER_KEYWORD_PORT "port"
#define PARSER_KEYWORD_PRAND_FACTOR_L "prand_factor_l"
#define PARSER_KEYWORD_PRAND_FACTOR_R "prand_factor_r"
#define PARSER_KEYWORD_PROFILE "profile"
#define PARSER_KEYWORD_PROPER_GOAL_KICKS "proper_goal_kicks"
#define PARSER_KEYWORD_QUANTIZE_STEP "quantize_step"
#define PARSER_KEYWORD_QUANTIZE_STEP_L "quantize_step_l"
#define PARSER_KEYWORD_RECORD_MESSAGES "record_messages"
#define PARSER_KEYWORD_RECOVER_DEC "recover_dec"
#define PARSER_KEYWORD_RECOVER_DEC_THR "recover_dec_thr"
#define PARSER_KEYWORD_RECOVER_INIT "recover_init"
#define PARSER_KEYWORD_RECOVER_MIN "recover_min"
#define PARSER_KEYWORD_RECIEVE_STEP "recv_step"
#define PARSER_KEYWORD_RED_CARD_PROBABILITY "red_card_probability"
#define PARSER_KEYWORD_SAY_COACH_CNT_MAX "say_coach_cnt_max"
#define PARSER_KEYWORD_SAY_COACH_MESSAGE_SIZE "say_coach_msg_size"
#define PARSER_KEYWORD_SAY_MESSAGE_SIZE "say_msg_size"
#define PARSER_KEYWORD_SEND_COMMS "send_comms"
#define PARSER_KEYWORD_SEND_STEP "send_step"
#define PARSER_KEYWORD_SEND_VI_STEP "send_vi_step"
#define PARSER_KEYWORD_SENSE_BODY_STEP "sense_body_step"
#define PARSER_KEYWORD_SIDE_DASH_RATE "side_dash_rate"
#define PARSER_KEYWORD_SIMULATOR_STEP "simulator_step"
#define PARSER_KEYWORD_SLOW_DOWN_FACTOR "slow_down_factor"
#define PARSER_KEYWORD_SLOWNESS_ON_TOP_FOR_LEFT_TEAM "slowness_on_top_for_left_team"
#define PARSER_KEYWORD_SLOWNESS_ON_TOP_FOR_RIGHT_TEAM "slowness_on_top_for_right_team"
#define PARSER_KEYWORD_STAMINA_CAPACITY "stamina_capacity"
#define PARSER_KEYWORD_STAMINA_INC_MAX "stamina_inc_max"
#define PARSER_KEYWORD_STAMINA_MAX "stamina_max"
#define PARSER_KEYWORD_START_GOAL_L "start_goal_l"
#define PARSER_KEYWORD_START_GOAL_R "start_goal_r"
#define PARSER_KEYWORD_STOPPED_BALL_VEL "stopped_ball_vel"
#define PARSER_KEYWORD_SYNCH_MICRO_SLEEP "synch_micro_sleep"
#define PARSER_KEYWORD_SYNCH_MODE "synch_mode"
#define PARSER_KEYWORD_SYNCH_OFFSET "synch_offset"
#define PARSER_KEYWORD_SYNCH_SEE_OFFSET "synch_see_offset"
#define PARSER_KEYWORD_TACKLE_BACK_DIST "tackle_back_dist"
#define PARSER_KEYWORD_TACKLE_CYCLES "tackle_cycles"
#define PARSER_KEYWORD_TACKLE_DIST "tackle_dist"
#define PARSER_KEYWORD_TACKLE_EXPONENT "tackle_exponent"
#define PARSER_KEYWORD_TACKLE_POWER_RATE "tackle_power_rate"
#define PARSER_KEYWORD_TACKLE_RAND_FACTOR "tackle_rand_factor"
#define PARSER_KEYWORD_TACKLE_WIDTH "tackle_width"
#define PARSER_KEYWORD_TEAM_ACTUATOR_NOISE "team_actuator_noise"
#define PARSER_KEYWORD_TEAM_L_START "team_l_start"
#define PARSER_KEYWORD_TEAM_R_START "team_r_start"
#define PARSER_KEYWORD_TEXT_LOG_COMPRESSION "text_log_compression"
#define PARSER_KEYWORD_TEXT_LOG_DATED "text_log_dated"
#define PARSER_KEYWORD_TEXT_LOG_DIR "text_log_dir"
#define PARSER_KEYWORD_TEXT_LOG_FIXED "text_log_fixed"
#define PARSER_KEYWORD_TEXT_LOG_FIXED_NAME "text_log_fixed_name"
#define PARSER_KEYWORD_TEXT_LOGGING "text_logging"
#define PARSER_KEYWORD_USE_OFFSIDE "use_offside"
#define PARSER_KEYWORD_VERBOSE "verbose"
#define PARSER_KEYWORD_VISIBLE_ANGLE "visible_angle"
#define PARSER_KEYWORD_VISIBLE_DISTANCE "visible_distance"
#define PARSER_KEYWORD_WIND_ANG "wind_ang"
#define PARSER_KEYWORD_WIND_DIR "wind_dir"
#define PARSER_KEYWORD_WIND_FORCE "wind_force"
#define PARSER_KEYWORD_WIND_NONE "wind_none"
#define PARSER_KEYWORD_WIND_RAND "wind_rand"
#define PARSER_KEYWORD_WIND_RANDOM "wind_random"
#define PARSER_KEYWORD_CATCHABLE_AREA_L_STRETCH "catchable_area_l_stretch"
#define PARSER_KEYWORD_ALLOW_MULTIPLE_DEFAULT_TYPE "allow_mult_default_type"
#define PARSER_KEYWORD_CATCHABLE_AREA_L_STRETCH_MAX "catchable_area_l_stretch_max"
#define PARSER_KEYWORD_CATCHABLE_AREA_L_STRETCH_MIN "catchable_area_l_stretch_min"
#define PARSER_KEYWORD_DASH_POWER_RATE_DELTA_MAX "dash_power_rate_delta_max"
#define PARSER_KEYWORD_DASH_POWER_RATE_DELTA_MIN "dash_power_rate_delta_min"
#define PARSER_KEYWORD_EFFORT_MAX_DELTA_FACTOR "effort_max_delta_factor"
#define PARSER_KEYWORD_EFFORT_MIN_DELTA_FACTOR "effort_min_delta_factor"
#define PARSER_KEYWORD_EXTRA_STAMINA_DELTA_MAX "extra_stamina_delta_max"
#define PARSER_KEYWORD_EXTRA_STAMINA_DELTA_MIN "extra_stamina_delta_min"
#define PARSER_KEYWORD_FOUL_DETECT_PROBABILITY_DELTA_FACTOR "foul_detect_probability_delta_factor"
#define PARSER_KEYWORD_INERTIA_MOMENT_DELTA_FACTOR "inertia_moment_delta_factor"
#define PARSER_KEYWORD_KICK_POWER_RATE_DELTA_MAX "kick_power_rate_delta_max"
#define PARSER_KEYWORD_KICK_POWER_RATE_DELTA_MIN "kick_power_rate_delta_min"
#define PARSER_KEYWORD_KICK_RAND_DELTA_FACTOR "kick_rand_delta_factor"
#define PARSER_KEYWORD_KICKABLE_MARGIN_DELTA_MAX "kickable_margin_delta_max"
#define PARSER_KEYWORD_KICKABLE_MARGIN_DELTA_MIN "kickable_margin_delta_min"
#define PARSER_KEYWORD_NEW_DASH_POWER_RATE_DELTA_MAX "new_dash_power_rate_delta_max"
#define PARSER_KEYWORD_NEW_DASH_POWER_RATE_DELTA_MIN "new_dash_power_rate_delta_min"
#define PARSER_KEYWORD_NEW_STAMINA_INC_MAX_DELTA_FACTOR "new_stamina_inc_max_delta_factor"
#define PARSER_KEYWORD_PLAYER_DECAY_DELTA_MAX "player_decay_delta_max"
#define PARSER_KEYWORD_PLAYER_DECAY_DELTA_MIN "player_decay_delta_min"
#define PARSER_KEYWORD_PLAYER_SIZE_DELTA_FACTOR "player_size_delta_factor"
#define PARSER_KEYWORD_PLAYER_SPEED_MAX_DELTA_MAX "player_speed_max_delta_max"
#define PARSER_KEYWORD_PLAYER_SPEED_MAX_DELTA_MIN "player_speed_max_delta_min"
#define PARSER_KEYWORD_PLAYER_TYPES "player_types"
#define PARSER_KEYWORD_PT_MAX "pt_max"
#define PARSER_KEYWORD_RANDOM_SEED "random_seed"
#define PARSER_KEYWORD_STAMINA_INC_MAX_DELTA_FACTOR "stamina_inc_max_delta_factor"
#define PARSER_KEYWORD_SUBS_MAX "subs_max"
#define PARSER_KEYWORD_PLAYER_TYPE "player_type"
#define PARSER_KEYWORD_ID "id"
#define PARSER_KEYWORD_SENSE_BODY "sense_body"
#define PARSER_KEYWORD_VIEW_MODE "view_mode"
#define PARSER_KEYWORD_STAMINA "stamina"
#define PARSER_KEYWORD_SPEED "speed"
#define PARSER_KEYWORD_HEAD_ANGLE "head_angle"
#define PARSER_KEYWORD_KICK "kick"
#define PARSER_KEYWORD_DASH "dash"
#define PARSER_KEYWORD_TURN "turn"
#define PARSER_KEYWORD_SAY "say"
#define PARSER_KEYWORD_TURN_NECK "turn_neck"
#define PARSER_KEYWORD_CATCH "catch"
#define PARSER_KEYWORD_MOVE "move"
#define PARSER_KEYWORD_CHANGE_VIEW "change_view"
#define PARSER_KEYWORD_ARM "arm"
#define PARSER_KEYWORD_MOVABLE "movable"
#define PARSER_KEYWORD_EXPIRES "expires"
#define PARSER_KEYWORD_TARGET "target"
#define PARSER_KEYWORD_COUNT "count"
#define PARSER_KEYWORD_FOCUS "focus"
#define PARSER_KEYWORD_TACKLE "tackle"
#define PARSER_KEYWORD_COLLISION "collision"
#define PARSER_KEYWORD_FOUL "foul"
#define PARSER_KEYWORD_CHARGED "charged"
#define PARSER_KEYWORD_CARD "card"
#define PARSER_KEYWORD_SEE "see"
#define PARSER_KEYWORD_PM_NULL "null"
#define PARSER_KEYWORD_PM_BEFORE_KICKOFF "before_kick_off"
#define PARSER_KEYWORD_PM_TIME_OVER "time_over"
#define PARSER_KEYWORD_PM_PLAY_ON "play_on"
#define PARSER_KEYWORD_PM_KICKOFF_LEFT "kick_off_l"
#define PARSER_KEYWORD_PM_KICKOFF_RIGHT "kick_off_r"
#define PARSER_KEYWORD_PM_KICK_IN_LEFT "kick_in_l"
#define PARSER_KEYWORD_PM_KICK_IN_RIGHT "kick_in_r"
#define PARSER_KEYWORD_PM_FREE_KICK_LEFT "free_kick_l"
#define PARSER_KEYWORD_PM_FREE_KICK_RIGHT "free_kick_r"
#define PARSER_KEYWORD_PM_CORNER_KICK_LEFT "corner_kick_l"
#define PARSER_KEYWORD_PM_CORNER_KICK_RIGHT "corner_kick_r"
#define PARSER_KEYWORD_PM_GOAL_KICK_LEFT "goal_kick_l"
#define PARSER_KEYWORD_PM_GOAL_KICK_RIGHT "goal_kick_r"
#define PARSER_KEYWORD_PM_AFTER_GOAL_LEFT ""
#define PARSER_KEYWORD_PM_AFTER_GOAL_RIGHT ""
#define PARSER_KEYWORD_PM_DROP_BALL ""
#define PARSER_KEYWORD_PM_OFFSIDE_LEFT ""
#define PARSER_KEYWORD_PM_OFFSIDE_RIGHT ""
#define PARSER_KEYWORD_PM_MAX ""
#define PARSER_KEYWORD_VIEWMODE_QUALITY_LOW "low"
#define PARSER_KEYWORD_VIEWMODE_QUALITY_HIGH "high"
#define PARSER_KEYWORD_VIEWMODE_WIDTH_NARROW "narrow"
#define PARSER_KEYWORD_VIEWMODE_WIDTH_NORMAL "normal"
#define PARSER_KEYWORD_VIEWMODE_WIDTH_WIDE "wide"
#define PARSER_KEYWORD_HEAR "hear"
#define PARSER_KEYWORD_REFEREE "referee"
#define PARSER_KEYWORD_F "f"
#define PARSER_KEYWORD_T "t"
#define PARSER_KEYWORD_B "b"
#define PARSER_KEYWORD_L "l"
#define PARSER_KEYWORD_R "r"
#define PARSER_KEYWORD_C "c"
#define PARSER_KEYWORD_G "g"
#define PARSER_KEYWORD_P "p"
#define PARSER_KEYWORD_P_CLOSE "P"
#define PARSER_KEYWORD_G_CLOSE "G"
#define PARSER_KEYWORD_B_CLOSE "B"
#define PARSER_KEYWORD_F_CLOSE "F"
#define PARSER_KEYWORD_10 "10"
#define PARSER_KEYWORD_20 "20"
#define PARSER_KEYWORD_30 "30"
#define PARSER_KEYWORD_40 "40"
#define PARSER_KEYWORD_50 "50"
#define PARSER_KEYWORD_0 "0"


#endif
