#pragma once

#define NODE_API_ENDPOINT_BASE "https://api.node.rainmaker.espressif.com/v1"

#define NODE_API_ENDPOINT_SUFFIX_FETCH "node/otafetch"
#define NODE_API_ENDPOINT_SUFFIX_REPORT "node/otastatus"

#define NODE_API_ERROR_CODE_NO_UPDATE_AVAILABLE 105065

#define NODE_API_FIELD_ERROR_CODE "error_code"
#define NODE_API_FIELD_DESCRIPTION "description"
#define NODE_API_FIELD_URL "url"
#define NODE_API_FIELD_METADATA "metadata"
#define NODE_API_FIELD_FW_VERSION "fw_version"
#define NODE_API_FIELD_JOB_ID "ota_job_id"
#define NODE_API_FIELD_FILE_SIZE "file_size"