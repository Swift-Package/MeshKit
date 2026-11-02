// swift-tools-version: 6.4
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "MeshKit",
	platforms: [.iOS(.v15), .macOS(.v26), .visionOS(.v26)],
    products: [
		// MARK: - 用来收敛项目中那些对 FDSMeshLib 库的扩展接口
        .library(name: "MeshKit", targets: ["MeshKit"]),
		.library(name: "FDSMeshLib", targets: ["FDSMeshLib"])
    ],
    targets: [
        .target(name: "MeshKit", dependencies: ["FDSMeshLib"]),
        .testTarget(name: "MeshKitTests", dependencies: ["MeshKit"]),
		.binaryTarget(name: "FDSMeshLib", path: "./Sources/FDSMeshLib.xcframework")
    ],
	swiftLanguageModes: [.v5]
)
