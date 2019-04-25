import sys, json, os, hashlib
from pathlib import Path
from Cheetah.Template import Template

def calc_hash( file_name ):
    with open(file_name,"rb") as f:
        bytes = f.read() # read entire file as bytes
        return hashlib.sha256(bytes).hexdigest();


def main(argv):
    n = len( argv )
    if n < 3:
        print ('not enough arguments: {}'.format(argv))
        sys.exit(2)

    try:
        template_path = argv[0]
        out_dir_path = Path(argv[1])
        os.makedirs(out_dir_path, exist_ok=True)
        inputs = argv[2:]

        template = Template.compile(
            file=template_path,
            compilerSettings=dict(directiveStartToken="//#", directiveEndToken="//#",
                                  commentStartToken="//##"), baseclass=dict, useCache=False)

        template_hash = calc_hash( template_path )
        for json_path in inputs:
            parameters_hash = calc_hash( json_path )
            output_path = out_dir_path / (Path( json_path ).stem + ".hpp")
            print( "Generating file: {}".format(output_path) )
            with open(json_path, 'r') as json_params_file:
                params_dict = json.load(json_params_file)
                params_dict['template_hash'] = template_hash
                params_dict['parameters_hash'] = parameters_hash
                with open(output_path, 'w') as fout:
                    fout.write( str(template(params_dict)) )
            print( "Generating OK" )
    except Exception as error:
      print (error)
      sys.exit(1)

if __name__ == "__main__":
   main( sys.argv[1:] )

