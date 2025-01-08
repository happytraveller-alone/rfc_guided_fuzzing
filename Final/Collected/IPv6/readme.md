# 文件夹名为取到特定的值收集到的报文

![alt text](image.png)

| 字段值 | 描述                                  |
| ------ | :------------------------------------ |
| 0      | Hop-by-Hop Options Header             |
| 43     | Routing Header                        |
| 44     | Fragment Header                       |
| 60     | Destination Options Header            |
| 51     | Authentication Header                 |
| 50     | Encapsulating security Payload Header |
| 59     | No Next Header                        |
| 6      | TCP                                   |
| 17     | UDP                                   |
| 58     | ICMPv6                                |



| NH字段的值 |                    描述                    |
| :--------: | :----------------------------------------: |
|            |           Extension Header Order           |
|            |                  Options                   |
|            |         Hop-by-Hop Options Header          |
|            |               Routing Header               |
|            |              Fragment Header               |
|            |         Destination Options Header         |
|            |               No Next Header               |
|            | Defining New Extension Headers and Options |
|            |                    TCP                     |
|            |                    UDP                     |
|            |                    ICMP                    |





```mermaid
graph TD
    start(开始) --> menu{显示菜单}
    menu -->|1. 增加一本新书| addBook[增加一本新书]
    menu -->|2. 删除一本书| deleteBook[删除一本书]
    menu -->|3. 借书| borrowBook[借书]
    menu -->|4. 还书| returnBook[还书]
    menu -->|5. 查看当前图书总数| showTotalBooks[查看当前图书总数]
    menu -->|6. 按图书名称排序| sortBooksByName[按图书名称排序]
    menu -->|7. 显示所有书籍| displayBooks[显示所有书籍]
    menu -->|8. 库存丢失记录| loseStockbook[库存丢失记录]
    menu -->|9. 借出书籍丢失记录| loseBorrowedBook[借出书籍丢失记录]
    menu -->|10. 统计特定种类书籍数量| countBooksByType[统计特定种类书籍数量]
    addBook -->|完成| menu
    deleteBook -->|完成| menu
    borrowBook -->|完成| menu
    returnBook -->|完成| menu
    showTotalBooks -->|完成| menu
    sortBooksByName -->|完成| menu
    displayBooks -->|完成| menu
    loseStockbook -->|完成| menu
    loseBorrowedBook -->|完成| menu
    countBooksByType -->|完成| menu
    menu -->|0. 退出| End
```

