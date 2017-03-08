# Description

In order to improve build speed of iroha and make it more stable and testable, `tiny` docker image is created.

It uses pre-built shared objects for linux x86_64 (which circle-ci is using) and very small Dockerfile.

It will be used mainly in circle-ci to build and test iroha.

Also (probably) it will be used as minified production version.