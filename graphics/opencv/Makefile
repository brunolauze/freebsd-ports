# Created by: Marc Abramowitz (http://marc.abramowitz.info)
# $FreeBSD: head/graphics/opencv/Makefile 336174 2013-12-11 15:04:33Z jhale $

PORTNAME?=	opencv
PORTVERSION=	2.4.8
PORTREVISION?=	1
CATEGORIES=	graphics
#MASTER_SITES=	SF/${PORTNAME}library/${PORTNAME}-unix/${PORTVERSION}

USE_GITHUB=	yes
GH_ACCOUNT=	Itseez
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	6fac92d

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Open Source Computer Vision library

LICENSE=	BSD
#BSD License file is now gone from repo
#LICENSE_FILE=	${WRKSRC}/doc/license.txt

USES=		cmake pkgconfig
USE_ZIP=	yes
USE_LDCONFIG=	yes
WANT_GSTREAMER1=	yes
MAKE_JOBS_UNSAFE=	yes

NOT_FOR_ARCHS=	sparc64
NOT_FOR_ARCHS_REASON_sparc64=	does not compile on sparc64

DATADIR=	${PREFIX}/share/OpenCV
PLIST_SUB+=	VERSION=${DISTVERSION}

CMAKE_ARGS+=	-DWITH_CUDA:BOOL=Off \
		-DWITH_PVAPI:BOOL=Off \
		-DWITH_UNICAP:BOOL=Off \
		-DBUILD_TESTS:BOOL=Off \
		-DBUILD_DOCS:BOOL=Off \
		-DPYTHON_EXECUTABLE:FILEPATH=${PYTHON_CMD}

SUB_FILES=	FindOpenCVCore.cmake
SUB_LIST=	OCV_VERSION=${PORTVERSION}

OCV_CORE_MODS=		core imgproc
OCV_MODS=		calib3d contrib features2d flann gpu \
			highgui legacy ml ocl objdetect photo \
			stitching superres ts video videostab
OCV_NONFREE_MODS=	nonfree
OCV_JAVA_MODS=		java
OCV_PYTHON_MODS=	python

OPTIONS_DEFINE=		DC1394 EXAMPLES NONFREE OPENGL
OPTIONS_GROUP=		IMAGE PERFORMANCE VIDEO
OPTIONS_GROUP_IMAGE=	JASPER JPEG OPENEXR PNG TIFF
OPTIONS_GROUP_PERFORMANCE=	EIGEN3 TBB
OPTIONS_GROUP_VIDEO=	FFMPEG GSTREAMER V4L XINE
OPTIONS_RADIO=		GUI
OPTIONS_RADIO_GUI=	GTK2 QT4
OPTIONS_DEFAULT=	EIGEN3 JASPER JPEG PNG TIFF V4L
OPTIONS_SUB=		yes
.if defined(OCV_CORE)
OPTIONS_EXCLUDE=	DC1394 EXAMPLES GTK2 QT4 JASPER JPEG NONFREE OPENEXR \
			OPENGL PNG TIFF FFMPEG GSTREAMER V4L XINE
.elif defined(OCV_PYTHON)
OPTIONS_EXCLUDE=	DC1394 GTK2 QT4 JASPER JPEG NONFREE OPENEXR \
			OPENGL PNG TIFF TBB EIGEN3 FFMPEG GSTREAMER V4L XINE
.endif

DC1394_DESC=		IEEE 1394 camera support
EIGEN3_DESC=		Eigen 3 support
IMAGE_DESC=		Image format support
NONFREE_DESC=		Build functionality that has possible limitations of use
PERFORMANCE_DESC=	Performance enhancing libraries
TBB_DESC=		TBB support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDC1394}
LIB_DEPENDS+=	libdc1394.so:${PORTSDIR}/multimedia/libdc1394
CMAKE_ARGS+=	-DWITH_1394:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_1394:BOOL=Off
.endif

.if ${PORT_OPTIONS:MEIGEN3}
BUILD_DEPENDS+=	${LOCALBASE}/include/eigen3/Eigen/Eigen:${PORTSDIR}/math/eigen3
CMAKE_ARGS+=	-DWITH_EIGEN:BOOL=On
.else
CMAKE_ARGS=	-DWITH_EIGEN:BOOL=Off
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	*
. if !defined(OCV_SLAVE)
CMAKE_ARGS+=	-DBUILD_EXAMPLES:BOOL=On \
		-DINSTALL_C_EXAMPLES:BOOL=On
. endif
.endif

.if ${PORT_OPTIONS:MFFMPEG}
LIB_DEPENDS+=	libavcodec.so:${PORTSDIR}/multimedia/ffmpeg
CMAKE_ARGS+=	-DWITH_FFMPEG:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_FFMPEG:BOOL=Off
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER1=	yes
CMAKE_ARGS+=	-DWITH_GSTREAMER:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_GSTREAMER:BOOL=Off
.endif

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
CMAKE_ARGS+=	-DWITH_GTK:BOOL=On
. if ${PORT_OPTIONS:MOPENGL}
LIB_DEPENDS+=	libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext
. endif
.else
CMAKE_ARGS+=	-DWITH_GTK:BOOL=Off
.endif

.if ${PORT_OPTIONS:MJASPER}
LIB_DEPENDS+=	libjasper.so:${PORTSDIR}/graphics/jasper
CMAKE_ARGS+=	-DWITH_JASPER:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_JASPER:BOOL=Off
.endif

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/libjpeg-turbo
CMAKE_ARGS+=	-DWITH_JPEG:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_JPEG:BOOL=Off
.endif

.if ${PORT_OPTIONS:MNONFREE}
CMAKE_ARGS+=	-DBUILD_opencv_nonfree:BOOL=On
.else
CMAKE_ARGS+=	-DBUILD_opencv_nonfree:BOOL=Off
.endif

.if ${PORT_OPTIONS:MOPENEXR}
LIB_DEPENDS+=	libIlmImf.so:${PORTSDIR}/graphics/OpenEXR
CMAKE_ARGS+=	-DWITH_OPENEXR:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_OPENEXR:BOOL=Off
.endif

.if ${PORT_OPTIONS:MOPENGL}
CMAKE_ARGS+=	-DWITH_OPENGL:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_OPENGL:BOOL=Off
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	libpng15.so:${PORTSDIR}/graphics/png
CMAKE_ARGS+=	-DWITH_PNG:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_PNG:BOOL=Off
.endif

.if ${PORT_OPTIONS:MQT4}
USE_QT4+=	gui moc_build qmake_build rcc_build uic_build qtestlib
CMAKE_ARGS+=	-DWITH_QT:STRING="4"
. if ${PORT_OPTIONS:MOPENGL}
USE_QT4+=	opengl
. endif
.else
CMAKE_ARGS+=	-DWITH_QT:BOOL=Off
.endif

.if ${PORT_OPTIONS:MTBB}
LIB_DEPENDS+=	libtbb.so:${PORTSDIR}/devel/tbb
CMAKE_ARGS+=	-DWITH_TBB:BOOL=On \
		-DTBB_INCLUDE_DIR:STRING="${LOCALBASE}/include"
.else
CMAKE_ARGS+=	-DWITH_TBB:BOOL=Off
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	libtiff.so:${PORTSDIR}/graphics/tiff
CMAKE_ARGS+=	-DWITH_TIFF:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_TIFF:BOOL=Off
.endif

.if ${PORT_OPTIONS:MV4L}
LIB_DEPENDS+=	libv4l2.so:${PORTSDIR}/multimedia/libv4l
BUILD_DEPENDS+=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
CMAKE_ARGS+=	-DWITH_V4L:BOOL=On \
		-DCMAKE_REQUIRED_INCLUDES:STRING="${LOCALBASE}/include"
.else
CMAKE_ARGS+=	-DWITH_V4L:BOOL=Off
.endif

.if ${PORT_OPTIONS:MXINE}
LIB_DEPENDS+=	libxine.so:${PORTSDIR}/multimedia/libxine
CMAKE_ARGS+=	-DWITH_XINE:BOOL=On
.else
CMAKE_ARGS+=	-DWITH_XINE:BOOL=Off
.endif

.if defined(OCV_CORE)
. for module in ${OCV_MODS} ${OCV_JAVA_MODS} ${OCV_PYTHON_MODS}
CMAKE_ARGS+=	-DBUILD_opencv_${module}:BOOL=Off
. endfor
.elif defined(OCV_PYTHON)
LIB_DEPENDS+=	libopencv_legacy.so:${PORTSDIR}/graphics/opencv
BUILD_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${PYNUMPY}
USE_PYTHON=	yes
CFLAGS+=	-I${LOCALBASE}/include
CMAKE_ARGS+=	-DBUILD_opencv_python:BOOL=On
. for module in ${OCV_MODS} ${OCV_CORE_MODS} ${OCV_JAVA_MODS}
CMAKE_ARGS+=	-DBUILD_opencv_${module}:BOOL=Off
. endfor
CMAKE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
INSTALL_WRKSRC=	${WRKSRC}/modules/python
.elif defined(OCV_JAVA)
BUILD_DEPENDS+=	ant:${PORTSDIR}/devel/apache-ant
LIB_DEPENDS+=	libopencv_legacy.so:${PORTSDIR}/graphics/opencv
USE_JAVA=	yes
USE_PYTHON_BUILD=	yes
CMAKE_ARGS+=	-DBUILD_opencv_java:BOOL=On
. for module in apps python stitching superres videostab
CMAKE_ARGS+=	-DBUILD_opencv_${module}:BOOL=Off
. endfor
CMAKE_ENV+=	JAVA_HOME="${JAVA_HOME}"
INSTALL_WRKSRC=	${WRKSRC}/modules/java
.else
LIB_DEPENDS+=	libopencv_core.so:${PORTSDIR}/graphics/opencv-core
. for module in ${OCV_JAVA_MODS} ${OCV_PYTHON_MODS}
CMAKE_ARGS+=	-DBUILD_opencv_${module}:BOOL=Off
. endfor
.endif

post-patch:
	@${MKDIR} ${CONFIGURE_WRKSRC}
	@${REINPLACE_CMD} -e '/pkgconfig/s|$${OPENCV_LIB_INSTALL_PATH}|libdata|' \
		 ${WRKSRC}/cmake/OpenCVGenPkgconfig.cmake
	@${REINPLACE_CMD} -e 's|share/OpenCV/doc|share/doc/${PORTNAME}|g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's|[Oo]pen[Cc][Vv]/samples|examples/${PORTNAME}|g' \
		${WRKSRC}/samples/*/CMakeLists.txt \
		${WRKSRC}/samples/*/*/CMakeLists.txt
	@${FIND} ${WRKSRC} -name '*.orig' -exec ${RM} {} \;
.if defined(OCV_CORE)
	@${REINPLACE_CMD} -e 's|opencv.pc|opencv-core.pc|g' \
		${WRKSRC}/cmake/OpenCVGenPkgconfig.cmake
	@${REINPLACE_CMD} -e 's|Name:.*|Name: OpenCV-core|' \
		${WRKSRC}/cmake/templates/opencv-XXX.pc.in
.endif
.if defined(OCV_PYTHON)
. for module in ${OCV_CORE_MODS} ${OCV_MODS} ${OCV_NONFREE_MODS}
	@${REINPLACE_CMD} -e 's|opencv_${module} | |' \
		-e 's|opencv_${module}$$||' \
		-e 's|opencv_${module})|)|' \
		${WRKSRC}/modules/*/CMakeLists.txt
. endfor
	${REINPLACE_CMD} -e '/[Ee][Xx][Pp][Oo][Rr][Tt]/d' \
		${WRKSRC}/cmake/OpenCVGenConfig.cmake
.endif

post-install:
.if defined(OCV_CORE)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cmake/Modules
	${INSTALL_DATA} ${WRKDIR}/FindOpenCVCore.cmake ${STAGEDIR}${PREFIX}/share/cmake/Modules
.endif
.if defined(OCV_PYTHON)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples/python && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/python
	cd ${WRKSRC}/samples/python2 && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/python2
.endif
.if defined(OCV_JAVA)
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples/java && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/java
.endif

.include <bsd.port.mk>
