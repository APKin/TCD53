//#include "Test.h"
//#include <DBHelper.h>
//#include <InstructLogDAO.cpp>
//// 创建DAO实例
//DBHelper dbHelper;
//InstructLogDAO logDao(dbHelper);
//
//// 插入示例
//InstructLog newLog;
//newLog.setType("控制指令");
//newLog.setContent("开启设备A");
//newLog.setCreateTime(QDateTime::currentDateTime());
//logDao.insert(newLog);
//
//// 条件查询示例
//QDateTime start = QDateTime(QDate(2023, 1, 1), QTime(0, 0));
//QDateTime end = QDateTime::currentDateTime();
//QList<InstructLog> results = logDao.findByCondition(
//    "控制",  // 类型关键词
//    "设备A", // 内容关键词
//    start,   // 开始时间
//    end      // 结束时间
//);
//
//// 更新示例
//if (!results.isEmpty()) {
//    InstructLog log = results.first();
//    log.setContent("关闭设备A");
//    logDao.update(log);
//}
//
//// 删除示例
//logDao.remove(5); // 删除ID=5的记录