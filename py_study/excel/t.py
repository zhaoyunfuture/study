import os, sys, getopt
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

 if __name__ == '__cli__':
     print('Testing %s >>>\n' % __file__)
     print "current working directory {}".format(os.getcwd())
     opts, args = getopt.getopt(sys.argv[1:], 'i:o:h', ['input_path=', 'output_path=', 'help'])
     print opts
     print args
     proto_path = ''
     protoc= ''
     for key, value in opts:
         if key in ['-i', '--input_path']:
             protoc = value
         if key in ['-o', '--output_path']:
             proto_path = value
         if key in ['-h', '--help']:
             print "please check below parameters"
             print " --input_path/-i : input path"
             print " --output_path/-o : output path"
             sys.exit(0)
     if input_path.strip() == '' or output_path.strip() == '':
         print "parameter wrong"
     else:
         print "pass"

