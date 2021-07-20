function scheduleHtmlProvider(iframeContent = "", frameContent = "", dom = document) {
    const ifrs = dom.getElementsByTagName("iframe");
    const frs = dom.getElementsByTagName("frame");
    /*取表格所在网页*/
    for (let i = 0; i < frs.length; i++) {
        const dom = frs[i].contentDocument.body.parentElement;
        frameContent += scheduleHtmlProvider(iframeContent, frameContent, dom);
    }
    return dom.getElementsByTagName('html')[0].innerHTML + iframeContent + frameContent
}

function scheduleHtmlParser(html) {
    /*时间表*/
    var startTime = ['08:00', '08:50', '10:00', '10:50', '13:30', '14:20', '15:30', '16:20', '17:50', '19:00', '19:50', '20:40']
    var endTime = ['08:45', '09:35', '10:45', '11:35', '14:15', '15:05', '16:15', '17:05', '18:35', '19:45', '20:35', '21:25']
    var sectionTime = [
        {
            "section": 1,
            "startTime": startTime[0],
            "endTime": endTime[0]
        },
        {
            "section": 2,
            "startTime": startTime[1],
            "endTime": endTime[1]
        },
        {
            "section": 3,
            "startTime": startTime[2],
            "endTime": endTime[2]
        },
        {
            "section": 4,
            "startTime": startTime[3],
            "endTime": endTime[3]
        },
        {
            "section": 5,
            "startTime": startTime[4],
            "endTime": endTime[4]
        },
        {
            "section": 6,
            "startTime": startTime[5],
            "endTime": endTime[5]
        },
        {
            "section": 7,
            "startTime": startTime[6],
            "endTime": endTime[6]
        },
        {
            "section": 8,
            "startTime": startTime[7],
            "endTime": endTime[7]
        },
        {
            "section": 9,
            "startTime": startTime[8],
            "endTime": endTime[8]
        },
        {
            "section": 10,
            "startTime": startTime[9],
            "endTime": endTime[9]
        },
        {
            "section": 11,
            "startTime": startTime[10],
            "endTime": endTime[10]
        },
        {
            "section": 12,
            "startTime": startTime[11],
            "endTime": endTime[11]
        }
    ];

    let table = $('.classTimeTable')  //取表格
    let rows = table.find('tr')
    let infos = []    //存储单元格信息
    let jies = []     //存储单元格的节数（2,3……）
    let lens = []     //存储单元格的节次（第几节开始）
    let xinqis = []   //存储单元格的周次
    let xinqitemp

    /* 处理单元格 */
    cellDeal()
    /*处理数据*/
    let result = resultDeal()
    //数据处理完成
    return { courseInfos: result, sectionTimes: sectionTime }

    /* innerFunctions */
    /* 处理数据 */
    function resultDeal() {
        let result = [];
        for (let i = 0; i < infos.length; i++) //对每一元素操作
        {
            let teachers = [];
            let tempinfos = [];
            teachers = infos[i].match(/[\u4e00-\u9fa5]+\([0-9]{5}\)/g);
            //去除教师编号
            for (let r = 0; r < teachers.length; r++) {
                teachers[r] = teachers[r].match(/[\u4e00-\u9fa5]+/)[0];
            }
            //分隔同一时间不同节课程
            tempinfos = infos[i].split(/[\u4e00-\u9fa5]+\([0-9]{5}\)/);
            //删除空元素
            for (let r = 0; r < tempinfos.length; r++) {
                if (tempinfos[r] == '') {
                    tempinfos.splice(r, 1);
                }
            }
            //删除多个教师同一堂课的多余元素
            for (let r = 0; r < tempinfos.length; r++) {
                if (tempinfos[r] == ',') {
                    tempinfos.splice(r, 1);
                    teachers[r] = teachers[r] + ',' + teachers[r + 1];
                    teachers.splice(r + 1, 1);
                }
            }
            for (let r = 0; r < tempinfos.length; r++) {
                let tempname = tempinfos[r].split(/\[+.*\]/)[0].split(/\(.{8}\)/)[0].trim();
                let tempweek = tempinfos[r].match(/\[+.*\]/)[0].trim();
                let temploc = tempinfos[r].split(/\[+.*\]/)[1].trim();

                //处理星期
                let start;
                let end;
                let tmp = [];
                var reg = /([0-9]+)-([0-9]+)/;

                if (reg.test(tempweek)) //若是？-？？型
                {
                    start = (Number)(RegExp.$1);
                    end = (Number)(RegExp.$2);
                    if (tempweek.search('单') != -1) //若单周
                    {
                        //let tmp=[]
                        for (let y = start; y <= end; y++) {
                            if (y % 2 == 1) {
                                tmp.push((Number)(y));
                            }
                        }
                    }
                    else if (tempweek.search('双') != -1) {
                        //let tmp=[]
                        for (let y = start; y <= end; y++) {
                            if (y % 2 == 0) {
                                tmp.push((Number)(y));
                            }
                        }
                    }
                    else {
                        for (let y = start; y <= end; y++) {
                            tmp.push((Number)(y));
                        }
                    }
                }
                else {
                    tmp = tempweek.split('[')[1].split(']')[0].split(',');
                    for (let x = 0; x < tmp.length; x++) {
                        tmp[x] = (Number)(tmp[x]);
                    }
                }
                let jiecis = [];
                for (let m = lens[i]; m < lens[i] + jies[i]; m++) {
                    jiecis.push(m);
                }

                //整合数据赋值
                var lesson = {
                    "name": tempname,
                    "position": temploc,
                    "teacher": teachers[r],
                    "weeks": tmp,
                    "day": xinqis[i],
                    "sections": [{
                        "section": jiecis
                    }]
                };
                result.push(lesson);
            }
        }
        return result;
    }

    /* 处理单元格 */
    function cellDeal() {
        for (let p = 0; p < rows.length; p++) //对每一行操作
        {
            for (let y = 0; y < rows[p].children.length; y++) //对每一单元格操作
            {
                let cell = rows[p].children[y];
                if (cell.name == 'td') {
                    xinqitemp = cell.attribs['data-index']; //所在星期
                    if (xinqitemp != 0 && cell.children[0].children[0].name == 'span') //非边界单元格&&有课单元格
                    {
                        let jie = cell.attribs.rowspan; //课程长度
                        let info = cellToInfo(cell, info, p, jie);  //处理单个单元格
                    }
                }
            }
        }

        /*处理单个单元格*/
        function cellToInfo(cell, info, p, jie) {
            for (let i = 0; i < cell.children.length; i++) {
                for (let k = 0; k < cell.children[i].children.length; k++) {
                    for (let j = 0; j < cell.children[i].children[k].children.length; j++) {
                        if (cell.children[i].name == 'div'
                            && cell.children[i].children[k].name == 'span'
                            && cell.children[i].children[k].children[j].name == 'span') {
                            let truecell = cell.children[i].children[k].children[j].children[0];
                            while (truecell.data == undefined) {
                                truecell = truecell.children[0];
                            }
                            info = truecell.data;
                            lens.push(p);
                            infos.push(info);
                            jies.push((Number)(jie));
                            xinqis.push((Number)(xinqitemp));
                            //结束循环
                            return info;
                        }
                    }
                }
            }
        }
    }
}