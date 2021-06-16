import sys
import xlrd
import xlwt

def open_excel(file= 'file.xls'):
    try:
        data = xlrd.open_workbook(file)
        return data
    except :
        print('error open file')

if __name__ == '__main__':
    data = open_excel('test.xls')
    table = data.sheets()[0]
    nrows = table.nrows
    ncols = table.ncols
    print('nrows=%d' % nrows)
    print('ncols=%d' % ncols)
    #d1 = table.row_values(0)[1]
    #print d1
    #for i in range(nrows):
    #    print table.row_values(i)[0]

    out = xlwt.Workbook()
    out_sheet = out.add_sheet('Result Sheet')
    for i in range(ncols):
        tmp = 0
        for j in range(i+1):
            tmp += table.row_values(0)[j]
        out_sheet.write(0,i,tmp)
    out.save('result.xls')
    pass

