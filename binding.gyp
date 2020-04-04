{
    "targets": [
    {
        "target_name": "targetHello",
        "cflags!": [ "-fno-exceptions" ],
        "cflags_cc!": [ "-fno-exceptions" ],
        "sources": [
	    "src/main.cpp",
	    "src/Wrappers.cpp"
        ],
        'include_dirs': [
            "<!@(node -p \"require('node-addon-api').include\")",
	    "include"
        ],
        'libraries': [
	    "<(module_root_dir)/lib/Hello.a"
	],
        'dependencies': [
            "<!(node -p \"require('node-addon-api').gyp\")",
        ],
        'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }
    ]
}
