node('osx') {
  stage 'checkout'
  checkout scm
  sh 'git submodule update --init --recursive'

  stage 'prepare'
  sh "./cmake_osx_xcode_project.sh"

  stage 'build'
  sh "xcodebuild -project garbage/ToyGine.xcodeproj -alltargets -configuration Debug"

  stage 'tests'
  sh "garbage/test/unittest/Debug/unittest --reporter junit --out garbage/junit-report.xml"

  stage 'static analysis'
  sh "./build/run_cpplint.sh"

  step([$class: 'WarningsPublisher', canComputeNew: true, useDeltaValues: true, useStableBuildAsReference: true, canResolveRelativePaths: true, defaultEncoding: '', excludePattern: '', healthy: '', includePattern: '', messagesPattern: '', consoleParsers: [[parserName: 'CppLint']], unHealthy: ''])
  step([$class: 'JUnitResultArchiver', testResults: 'garbage/junit-report.xml'])
}
