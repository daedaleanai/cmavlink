// Generated enums and structures for Mavlink dialect matrixpilot #0 version 3
// Generated by gomavlink, DO NOT EDIT.

#include "matrixpilot.h"

// Internal function used by both serialisation and deserialisation.
uint8_t matrixpilot_crcextra(enum MATRIXPILOT_MESSAGE mid) {
  switch (mid) {
  case MATRIXPILOT_MESSAGE_HEARTBEAT:
    return 50;

  case MATRIXPILOT_MESSAGE_SYS_STATUS:
    return 124;

  case MATRIXPILOT_MESSAGE_SYSTEM_TIME:
    return 137;

  case MATRIXPILOT_MESSAGE_PING:
    return 237;

  case MATRIXPILOT_MESSAGE_CHANGE_OPERATOR_CONTROL:
    return 217;

  case MATRIXPILOT_MESSAGE_CHANGE_OPERATOR_CONTROL_ACK:
    return 104;

  case MATRIXPILOT_MESSAGE_AUTH_KEY:
    return 119;

  case MATRIXPILOT_MESSAGE_LINK_NODE_STATUS:
    return 117;

  case MATRIXPILOT_MESSAGE_SET_MODE:
    return 89;

  case MATRIXPILOT_MESSAGE_PARAM_REQUEST_READ:
    return 214;

  case MATRIXPILOT_MESSAGE_PARAM_REQUEST_LIST:
    return 159;

  case MATRIXPILOT_MESSAGE_PARAM_VALUE:
    return 220;

  case MATRIXPILOT_MESSAGE_PARAM_SET:
    return 168;

  case MATRIXPILOT_MESSAGE_GPS_RAW_INT:
    return 24;

  case MATRIXPILOT_MESSAGE_GPS_STATUS:
    return 23;

  case MATRIXPILOT_MESSAGE_SCALED_IMU:
    return 170;

  case MATRIXPILOT_MESSAGE_RAW_IMU:
    return 144;

  case MATRIXPILOT_MESSAGE_RAW_PRESSURE:
    return 67;

  case MATRIXPILOT_MESSAGE_SCALED_PRESSURE:
    return 115;

  case MATRIXPILOT_MESSAGE_ATTITUDE:
    return 39;

  case MATRIXPILOT_MESSAGE_ATTITUDE_QUATERNION:
    return 246;

  case MATRIXPILOT_MESSAGE_LOCAL_POSITION_NED:
    return 185;

  case MATRIXPILOT_MESSAGE_GLOBAL_POSITION_INT:
    return 104;

  case MATRIXPILOT_MESSAGE_RC_CHANNELS_SCALED:
    return 237;

  case MATRIXPILOT_MESSAGE_RC_CHANNELS_RAW:
    return 244;

  case MATRIXPILOT_MESSAGE_SERVO_OUTPUT_RAW:
    return 222;

  case MATRIXPILOT_MESSAGE_MISSION_REQUEST_PARTIAL_LIST:
    return 212;

  case MATRIXPILOT_MESSAGE_MISSION_WRITE_PARTIAL_LIST:
    return 9;

  case MATRIXPILOT_MESSAGE_MISSION_ITEM:
    return 254;

  case MATRIXPILOT_MESSAGE_MISSION_REQUEST:
    return 230;

  case MATRIXPILOT_MESSAGE_MISSION_SET_CURRENT:
    return 28;

  case MATRIXPILOT_MESSAGE_MISSION_CURRENT:
    return 28;

  case MATRIXPILOT_MESSAGE_MISSION_REQUEST_LIST:
    return 132;

  case MATRIXPILOT_MESSAGE_MISSION_COUNT:
    return 221;

  case MATRIXPILOT_MESSAGE_MISSION_CLEAR_ALL:
    return 232;

  case MATRIXPILOT_MESSAGE_MISSION_ITEM_REACHED:
    return 11;

  case MATRIXPILOT_MESSAGE_MISSION_ACK:
    return 153;

  case MATRIXPILOT_MESSAGE_SET_GPS_GLOBAL_ORIGIN:
    return 41;

  case MATRIXPILOT_MESSAGE_GPS_GLOBAL_ORIGIN:
    return 39;

  case MATRIXPILOT_MESSAGE_PARAM_MAP_RC:
    return 78;

  case MATRIXPILOT_MESSAGE_MISSION_REQUEST_INT:
    return 196;

  case MATRIXPILOT_MESSAGE_MISSION_CHANGED:
    return 132;

  case MATRIXPILOT_MESSAGE_SAFETY_SET_ALLOWED_AREA:
    return 15;

  case MATRIXPILOT_MESSAGE_SAFETY_ALLOWED_AREA:
    return 3;

  case MATRIXPILOT_MESSAGE_ATTITUDE_QUATERNION_COV:
    return 167;

  case MATRIXPILOT_MESSAGE_NAV_CONTROLLER_OUTPUT:
    return 183;

  case MATRIXPILOT_MESSAGE_GLOBAL_POSITION_INT_COV:
    return 119;

  case MATRIXPILOT_MESSAGE_LOCAL_POSITION_NED_COV:
    return 191;

  case MATRIXPILOT_MESSAGE_RC_CHANNELS:
    return 118;

  case MATRIXPILOT_MESSAGE_REQUEST_DATA_STREAM:
    return 148;

  case MATRIXPILOT_MESSAGE_DATA_STREAM:
    return 21;

  case MATRIXPILOT_MESSAGE_MANUAL_CONTROL:
    return 243;

  case MATRIXPILOT_MESSAGE_RC_CHANNELS_OVERRIDE:
    return 124;

  case MATRIXPILOT_MESSAGE_MISSION_ITEM_INT:
    return 38;

  case MATRIXPILOT_MESSAGE_VFR_HUD:
    return 20;

  case MATRIXPILOT_MESSAGE_COMMAND_INT:
    return 158;

  case MATRIXPILOT_MESSAGE_COMMAND_LONG:
    return 152;

  case MATRIXPILOT_MESSAGE_COMMAND_ACK:
    return 143;

  case MATRIXPILOT_MESSAGE_MANUAL_SETPOINT:
    return 106;

  case MATRIXPILOT_MESSAGE_SET_ATTITUDE_TARGET:
    return 49;

  case MATRIXPILOT_MESSAGE_ATTITUDE_TARGET:
    return 22;

  case MATRIXPILOT_MESSAGE_SET_POSITION_TARGET_LOCAL_NED:
    return 143;

  case MATRIXPILOT_MESSAGE_POSITION_TARGET_LOCAL_NED:
    return 140;

  case MATRIXPILOT_MESSAGE_SET_POSITION_TARGET_GLOBAL_INT:
    return 5;

  case MATRIXPILOT_MESSAGE_POSITION_TARGET_GLOBAL_INT:
    return 150;

  case MATRIXPILOT_MESSAGE_LOCAL_POSITION_NED_SYSTEM_GLOBAL_OFFSET:
    return 231;

  case MATRIXPILOT_MESSAGE_HIL_STATE:
    return 183;

  case MATRIXPILOT_MESSAGE_HIL_CONTROLS:
    return 63;

  case MATRIXPILOT_MESSAGE_HIL_RC_INPUTS_RAW:
    return 54;

  case MATRIXPILOT_MESSAGE_HIL_ACTUATOR_CONTROLS:
    return 47;

  case MATRIXPILOT_MESSAGE_OPTICAL_FLOW:
    return 175;

  case MATRIXPILOT_MESSAGE_GLOBAL_VISION_POSITION_ESTIMATE:
    return 102;

  case MATRIXPILOT_MESSAGE_VISION_POSITION_ESTIMATE:
    return 158;

  case MATRIXPILOT_MESSAGE_VISION_SPEED_ESTIMATE:
    return 208;

  case MATRIXPILOT_MESSAGE_VICON_POSITION_ESTIMATE:
    return 56;

  case MATRIXPILOT_MESSAGE_HIGHRES_IMU:
    return 93;

  case MATRIXPILOT_MESSAGE_OPTICAL_FLOW_RAD:
    return 138;

  case MATRIXPILOT_MESSAGE_HIL_SENSOR:
    return 108;

  case MATRIXPILOT_MESSAGE_SIM_STATE:
    return 32;

  case MATRIXPILOT_MESSAGE_RADIO_STATUS:
    return 185;

  case MATRIXPILOT_MESSAGE_FILE_TRANSFER_PROTOCOL:
    return 84;

  case MATRIXPILOT_MESSAGE_TIMESYNC:
    return 34;

  case MATRIXPILOT_MESSAGE_CAMERA_TRIGGER:
    return 174;

  case MATRIXPILOT_MESSAGE_HIL_GPS:
    return 124;

  case MATRIXPILOT_MESSAGE_HIL_OPTICAL_FLOW:
    return 237;

  case MATRIXPILOT_MESSAGE_HIL_STATE_QUATERNION:
    return 4;

  case MATRIXPILOT_MESSAGE_SCALED_IMU2:
    return 76;

  case MATRIXPILOT_MESSAGE_LOG_REQUEST_LIST:
    return 128;

  case MATRIXPILOT_MESSAGE_LOG_ENTRY:
    return 56;

  case MATRIXPILOT_MESSAGE_LOG_REQUEST_DATA:
    return 116;

  case MATRIXPILOT_MESSAGE_LOG_DATA:
    return 134;

  case MATRIXPILOT_MESSAGE_LOG_ERASE:
    return 237;

  case MATRIXPILOT_MESSAGE_LOG_REQUEST_END:
    return 203;

  case MATRIXPILOT_MESSAGE_GPS_INJECT_DATA:
    return 250;

  case MATRIXPILOT_MESSAGE_GPS2_RAW:
    return 87;

  case MATRIXPILOT_MESSAGE_POWER_STATUS:
    return 203;

  case MATRIXPILOT_MESSAGE_SERIAL_CONTROL:
    return 220;

  case MATRIXPILOT_MESSAGE_GPS_RTK:
    return 25;

  case MATRIXPILOT_MESSAGE_GPS2_RTK:
    return 226;

  case MATRIXPILOT_MESSAGE_SCALED_IMU3:
    return 46;

  case MATRIXPILOT_MESSAGE_DATA_TRANSMISSION_HANDSHAKE:
    return 29;

  case MATRIXPILOT_MESSAGE_ENCAPSULATED_DATA:
    return 223;

  case MATRIXPILOT_MESSAGE_DISTANCE_SENSOR:
    return 85;

  case MATRIXPILOT_MESSAGE_TERRAIN_REQUEST:
    return 6;

  case MATRIXPILOT_MESSAGE_TERRAIN_DATA:
    return 229;

  case MATRIXPILOT_MESSAGE_TERRAIN_CHECK:
    return 203;

  case MATRIXPILOT_MESSAGE_TERRAIN_REPORT:
    return 1;

  case MATRIXPILOT_MESSAGE_SCALED_PRESSURE2:
    return 195;

  case MATRIXPILOT_MESSAGE_ATT_POS_MOCAP:
    return 109;

  case MATRIXPILOT_MESSAGE_SET_ACTUATOR_CONTROL_TARGET:
    return 168;

  case MATRIXPILOT_MESSAGE_ACTUATOR_CONTROL_TARGET:
    return 181;

  case MATRIXPILOT_MESSAGE_ALTITUDE:
    return 47;

  case MATRIXPILOT_MESSAGE_RESOURCE_REQUEST:
    return 72;

  case MATRIXPILOT_MESSAGE_SCALED_PRESSURE3:
    return 131;

  case MATRIXPILOT_MESSAGE_FOLLOW_TARGET:
    return 127;

  case MATRIXPILOT_MESSAGE_CONTROL_SYSTEM_STATE:
    return 103;

  case MATRIXPILOT_MESSAGE_BATTERY_STATUS:
    return 154;

  case MATRIXPILOT_MESSAGE_AUTOPILOT_VERSION:
    return 178;

  case MATRIXPILOT_MESSAGE_LANDING_TARGET:
    return 200;

  case MATRIXPILOT_MESSAGE_FLEXIFUNCTION_SET:
    return 181;

  case MATRIXPILOT_MESSAGE_FLEXIFUNCTION_READ_REQ:
    return 26;

  case MATRIXPILOT_MESSAGE_FLEXIFUNCTION_BUFFER_FUNCTION:
    return 101;

  case MATRIXPILOT_MESSAGE_FLEXIFUNCTION_BUFFER_FUNCTION_ACK:
    return 109;

  case MATRIXPILOT_MESSAGE_FLEXIFUNCTION_DIRECTORY:
    return 12;

  case MATRIXPILOT_MESSAGE_FLEXIFUNCTION_DIRECTORY_ACK:
    return 218;

  case MATRIXPILOT_MESSAGE_FLEXIFUNCTION_COMMAND:
    return 133;

  case MATRIXPILOT_MESSAGE_FLEXIFUNCTION_COMMAND_ACK:
    return 208;

  case MATRIXPILOT_MESSAGE_SERIAL_UDB_EXTRA_F2_A:
    return 103;

  case MATRIXPILOT_MESSAGE_SERIAL_UDB_EXTRA_F2_B:
    return 245;

  case MATRIXPILOT_MESSAGE_SERIAL_UDB_EXTRA_F4:
    return 191;

  case MATRIXPILOT_MESSAGE_SERIAL_UDB_EXTRA_F5:
    return 54;

  case MATRIXPILOT_MESSAGE_SERIAL_UDB_EXTRA_F6:
    return 54;

  case MATRIXPILOT_MESSAGE_SERIAL_UDB_EXTRA_F7:
    return 171;

  case MATRIXPILOT_MESSAGE_SERIAL_UDB_EXTRA_F8:
    return 142;

  case MATRIXPILOT_MESSAGE_SERIAL_UDB_EXTRA_F13:
    return 249;

  case MATRIXPILOT_MESSAGE_SERIAL_UDB_EXTRA_F14:
    return 123;

  case MATRIXPILOT_MESSAGE_SERIAL_UDB_EXTRA_F15:
    return 7;

  case MATRIXPILOT_MESSAGE_SERIAL_UDB_EXTRA_F16:
    return 222;

  case MATRIXPILOT_MESSAGE_ALTITUDES:
    return 55;

  case MATRIXPILOT_MESSAGE_AIRSPEEDS:
    return 154;

  case MATRIXPILOT_MESSAGE_SERIAL_UDB_EXTRA_F17:
    return 175;

  case MATRIXPILOT_MESSAGE_SERIAL_UDB_EXTRA_F18:
    return 41;

  case MATRIXPILOT_MESSAGE_SERIAL_UDB_EXTRA_F19:
    return 87;

  case MATRIXPILOT_MESSAGE_SERIAL_UDB_EXTRA_F20:
    return 144;

  case MATRIXPILOT_MESSAGE_SERIAL_UDB_EXTRA_F21:
    return 134;

  case MATRIXPILOT_MESSAGE_SERIAL_UDB_EXTRA_F22:
    return 91;

  case MATRIXPILOT_MESSAGE_ESTIMATOR_STATUS:
    return 163;

  case MATRIXPILOT_MESSAGE_WIND_COV:
    return 105;

  case MATRIXPILOT_MESSAGE_GPS_INPUT:
    return 151;

  case MATRIXPILOT_MESSAGE_GPS_RTCM_DATA:
    return 35;

  case MATRIXPILOT_MESSAGE_HIGH_LATENCY:
    return 150;

  case MATRIXPILOT_MESSAGE_HIGH_LATENCY2:
    return 179;

  case MATRIXPILOT_MESSAGE_VIBRATION:
    return 90;

  case MATRIXPILOT_MESSAGE_HOME_POSITION:
    return 104;

  case MATRIXPILOT_MESSAGE_SET_HOME_POSITION:
    return 85;

  case MATRIXPILOT_MESSAGE_MESSAGE_INTERVAL:
    return 95;

  case MATRIXPILOT_MESSAGE_EXTENDED_SYS_STATE:
    return 130;

  case MATRIXPILOT_MESSAGE_ADSB_VEHICLE:
    return 184;

  case MATRIXPILOT_MESSAGE_COLLISION:
    return 81;

  case MATRIXPILOT_MESSAGE_V2_EXTENSION:
    return 8;

  case MATRIXPILOT_MESSAGE_MEMORY_VECT:
    return 204;

  case MATRIXPILOT_MESSAGE_DEBUG_VECT:
    return 49;

  case MATRIXPILOT_MESSAGE_NAMED_VALUE_FLOAT:
    return 170;

  case MATRIXPILOT_MESSAGE_NAMED_VALUE_INT:
    return 44;

  case MATRIXPILOT_MESSAGE_STATUSTEXT:
    return 83;

  case MATRIXPILOT_MESSAGE_DEBUG:
    return 46;

  case MATRIXPILOT_MESSAGE_SETUP_SIGNING:
    return 71;

  case MATRIXPILOT_MESSAGE_BUTTON_CHANGE:
    return 131;

  case MATRIXPILOT_MESSAGE_PLAY_TUNE:
    return 187;

  case MATRIXPILOT_MESSAGE_CAMERA_INFORMATION:
    return 92;

  case MATRIXPILOT_MESSAGE_CAMERA_SETTINGS:
    return 146;

  case MATRIXPILOT_MESSAGE_STORAGE_INFORMATION:
    return 179;

  case MATRIXPILOT_MESSAGE_CAMERA_CAPTURE_STATUS:
    return 12;

  case MATRIXPILOT_MESSAGE_CAMERA_IMAGE_CAPTURED:
    return 133;

  case MATRIXPILOT_MESSAGE_FLIGHT_INFORMATION:
    return 49;

  case MATRIXPILOT_MESSAGE_MOUNT_ORIENTATION:
    return 26;

  case MATRIXPILOT_MESSAGE_LOGGING_DATA:
    return 193;

  case MATRIXPILOT_MESSAGE_LOGGING_DATA_ACKED:
    return 35;

  case MATRIXPILOT_MESSAGE_LOGGING_ACK:
    return 14;

  case MATRIXPILOT_MESSAGE_VIDEO_STREAM_INFORMATION:
    return 109;

  case MATRIXPILOT_MESSAGE_VIDEO_STREAM_STATUS:
    return 59;

  case MATRIXPILOT_MESSAGE_WIFI_CONFIG_AP:
    return 19;

  case MATRIXPILOT_MESSAGE_PROTOCOL_VERSION:
    return 217;

  case MATRIXPILOT_MESSAGE_UAVCAN_NODE_STATUS:
    return 28;

  case MATRIXPILOT_MESSAGE_UAVCAN_NODE_INFO:
    return 95;

  case MATRIXPILOT_MESSAGE_PARAM_EXT_REQUEST_READ:
    return 243;

  case MATRIXPILOT_MESSAGE_PARAM_EXT_REQUEST_LIST:
    return 88;

  case MATRIXPILOT_MESSAGE_PARAM_EXT_VALUE:
    return 243;

  case MATRIXPILOT_MESSAGE_PARAM_EXT_SET:
    return 78;

  case MATRIXPILOT_MESSAGE_PARAM_EXT_ACK:
    return 132;

  case MATRIXPILOT_MESSAGE_OBSTACLE_DISTANCE:
    return 23;

  case MATRIXPILOT_MESSAGE_ODOMETRY:
    return 91;

  case MATRIXPILOT_MESSAGE_TRAJECTORY_REPRESENTATION_WAYPOINTS:
    return 91;

  case MATRIXPILOT_MESSAGE_TRAJECTORY_REPRESENTATION_BEZIER:
    return 231;

  case MATRIXPILOT_MESSAGE_CELLULAR_STATUS:
    return 135;

  case MATRIXPILOT_MESSAGE_ISBD_LINK_STATUS:
    return 225;

  case MATRIXPILOT_MESSAGE_UTM_GLOBAL_POSITION:
    return 99;

  case MATRIXPILOT_MESSAGE_DEBUG_FLOAT_ARRAY:
    return 232;

  case MATRIXPILOT_MESSAGE_ORBIT_EXECUTION_STATUS:
    return 11;

  case MATRIXPILOT_MESSAGE_STATUSTEXT_LONG:
    return 36;

  case MATRIXPILOT_MESSAGE_SMART_BATTERY_INFO:
    return 98;

  case MATRIXPILOT_MESSAGE_SMART_BATTERY_STATUS:
    return 161;

  case MATRIXPILOT_MESSAGE_ACTUATOR_OUTPUT_STATUS:
    return 251;

  case MATRIXPILOT_MESSAGE_TIME_ESTIMATE_TO_TARGET:
    return 232;

  case MATRIXPILOT_MESSAGE_WHEEL_DISTANCE:
    return 113;
  }
  return 0;
}
