from flask import Flask,request, render_template,make_response
from flask_restful import Resource, Api
import subprocess, os

app = Flask(__name__)
api = Api(app)

class Compile(Resource):

    def get(self):
        return make_response(render_template('./index.html'),200)

    def post(self):
        command=['gcc source.c -o source.out','./source.out']
        data=request.form['source_input']
        try:
            _rw(data,'w')
            subprocess.call(command[0], shell=True)
            _output=subprocess.check_output(command[1], shell=True).decode('utf-8')
            os.remove('./source.out')
            return make_response(render_template('./index.html',result=_output),200)
        except Exception as errorLog:
            return make_response(render_template('./index.html',result=errorLog),400)

def _rw(data, flag):
    file=open('./source.c',flag)
    file.write(data)
    file.close


api.add_resource(Compile, '/')
if __name__ == '__main__':
    app.run(debug=True)