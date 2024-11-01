#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * 无错误。
 */
#define ERR_OK 0

/**
 * 配置路径错误。
 */
#define ERR_CONFIG_PATH 1

/**
 * 配置解析错误。
 */
#define ERR_CONFIG 2

/**
 * IO 错误。
 */
#define ERR_IO 3

/**
 * 配置文件监视器错误。
 */
#define ERR_WATCHER 4

/**
 * 异步通道发送错误。
 */
#define ERR_ASYNC_CHANNEL_SEND 5

/**
 * 同步通道接收错误。
 */
#define ERR_SYNC_CHANNEL_RECV 6

/**
 * 运行时管理器错误。
 */
#define ERR_RUNTIME_MANAGER 7

/**
 * 没有关联的配置文件。
 */
#define ERR_NO_CONFIG_FILE 8

/**
 * 使用选项启动 leaf，成功启动后此函数会阻塞当前线程。
 *
 * @note 这不是一个稳定的 API，参数会不时更改。
 *
 * @param rt_id 唯一 ID，用于关联此 leaf 实例，在调用后续 FFI 函数（如重载、关闭）时需要。
 * @param config_path 配置文件的路径，必须是后缀为 .conf 或 .json 的文件，具体取决于启用的功能。
 * @param auto_reload 当检测到配置文件更改时是否自动重新加载，仅在启用 "auto-reload" 功能时生效。
 * @param multi_thread 是否使用多线程运行时。
 * @param auto_threads 自动设置运行时工作线程的数量，仅在 multi_thread 为 true 时生效。
 * @param threads 设置运行时工作线程的数量，仅在 multi_thread 为 true 时生效，但可以被 auto_threads 覆盖。
 * @param stack_size 设置运行时工作线程的堆栈大小，仅在 multi_thread 为 true 时生效。
 * @return 成功运行时返回 ERR_OK，其他错误表示启动失败。
 */
int32_t leaf_run_with_options(uint16_t rt_id,
                              const char *config_path,
                              bool auto_reload,
                              bool multi_thread,
                              bool auto_threads,
                              int32_t threads,
                              int32_t stack_size);

/**
 * 使用单线程运行时启动 leaf，成功启动后此函数会阻塞当前线程。
 *
 * @param rt_id 唯一 ID，用于关联此 leaf 实例，在调用后续 FFI 函数（如重载、关闭）时需要。
 * @param config_path 配置文件的路径，必须是后缀为 .conf 或 .json 的文件，具体取决于启用的功能。
 * @return 成功运行时返回 ERR_OK，其他错误表示启动失败。
 */
int32_t leaf_run(uint16_t rt_id, const char *config_path);

int32_t leaf_run_with_config_string(uint16_t rt_id, const char *config);

/**
 * 从配置文件重新加载 DNS 服务器、出站和路由规则。
 *
 * @param rt_id 要重新加载的 leaf 实例的 ID。
 *
 * @return 成功时返回 ERR_OK。
 */
int32_t leaf_reload(uint16_t rt_id);

/**
 * 关闭 leaf。
 *
 * @param rt_id 要关闭的 leaf 实例的 ID。
 *
 * @return 成功时返回 true，失败时返回 false。
 */
bool leaf_shutdown(uint16_t rt_id);

/**
 * 测试配置。
 *
 * @param config_path 配置文件的路径，必须是后缀为 .conf 或 .json 的文件，具体取决于启用的功能。
 * @return 成功时返回 ERR_OK，即没有语法错误。
 */
int32_t leaf_test_config(const char *config_path);
