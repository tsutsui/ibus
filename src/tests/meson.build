ibus_tests = [
  { 'name': 'ibus-bus' },
  { 'name': 'ibus-config' },
  { 'name': 'ibus-configservice' },
  { 'name': 'ibus-factory' },
  { 'name': 'ibus-inputcontext' },
  { 'name': 'ibus-inputcontext-create' },
  { 'name': 'ibus-keynames' },
  { 'name': 'ibus-registry' },
  { 'name': 'ibus-serializable' },
  {
    'name': 'ibus-share',
    'extra_deps': [ dbus_dep ],
  },
  { 'name': 'ibus-util' },
  {
    'name': 'xkb-latin-layouts',
    'is-script': true,
    'dependencies': [ 'display' ],
  },
]

if get_option('engine')
  ibus_tests += { 'name': 'ibus-engine-switch' }
endif

if enable_gtk4 or enable_gtk3
  ibus_tests += {
    'name': 'ibus-compose',
    'extra_deps': [ gtk_dep ],
    'timeout': 300,
    'dependencies': [ 'display', 'wm' ],
  }

  if libevdev_dep.found() and libudev_dep.found()
    ibus_tests += {
      'name': 'ibus-keypress',
      'extra_sources': [ 'uinput-replay.c' ],
      'extra_deps': [ libevdev_dep, libudev_dep, gtk_dep ],
      'timeout': 60,
      'dependencies': [ 'display', 'wm' ],
    }
  endif
endif

ibus_tests_deps = [
  ibus_dep,
  glib_dep,
  gio_dep,
]

ibus_tests_cflags = [
  '-DIBUS_DISABLE_DEPRECATION_WARNINGS',
  '-DX11_LOCALEDATADIR="@0@"'.format(x11_localedatadir),
]

ibus_tests_runner = files(['runtest'])[0]

ibus_tests_env = {
  'top_builddir': build_root,
  'top_srcdir': source_root,
  'builddir': meson.current_build_dir(),
  'srcdir': meson.current_source_dir(),
}

foreach _test : ibus_tests
  if _test.get('is-script', false)
    test_bin = files([_test['name']])[0]
  else
    test_bin = executable(_test['name'],
      files(['@0@.c'.format(_test['name'])] + _test.get('extra_sources', [])),
      dependencies: ibus_tests_deps + _test.get('extra_deps', []),
      c_args: ibus_tests_cflags,
    )
  endif

  timeout = _test.get('timeout', 30)

  test(_test['name'], ibus_tests_runner,
    args: [ test_bin, meson.current_source_dir() ],
    env: environment(ibus_tests_env),
    suite: [ 'lib' ] + _test.get('dependencies', []),
    protocol: 'tap',
    timeout: timeout,
    is_parallel: false,
  )
endforeach

if libevdev_dep.found() and libudev_dep.found()
  uinput_replay_bin = executable('uinput-replay',
    sources: files(['uinput-replay.c']),
    c_args: [ '-DUINPUT_REPLAY_MAIN' ],
    include_directories: config_h_inc,
    dependencies: [ libevdev_dep, libudev_dep, glib_dep ],
  )
endif
