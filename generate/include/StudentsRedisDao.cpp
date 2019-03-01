///
/// @class StudentsRedisDao
/// @brief Redis底层接口类 操作students表
/// TABLE STUDENTS
/// @author dao_cpp_generator.py
/// @generate date: 2019-01-17 22:49:37
/// [注：本文件为自动生成，不需要人为编辑，若有修改，请通过配置py脚本来重新生成.]
include “StudentsRedisDao.h”
include “include/students_t.h”
include “RedisManager.h”
include “common/LogMacros.h”
include “common/StringUtility/OtherStringFunc.h”
include “common/DateTime.h”
namespace redisdao{

const string StudentsRedisDao::TABLE_NAME = “students”;
const string StudentsRedisDao::TABLE_ID = “115”; //在数据库中的表的唯一性标识符

StudentsRedisDao::StudentsRedisDao(void)
{
if ( 0 == m_reHandler.EnsureConnect())
    m_bRedisConnected = true;
else
    m_bRedisConnected = false;
}
StudentsRedisDao::~StudentsRedisDao(void)
{
}
int StudentsRedisDao::InsertRecord(const string& strVal)
