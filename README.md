# nendサービス終了に伴うnendSDKの削除のお願い

nendは2024年3月29日をもってサービスを終了いたします。  
サービス終了後は、Web, SDKいずれかの実装に関わらず広告配信の機能を停止いたします。  
それに伴い、アプリからnendSDKの削除をお願いいたします。  

## nendSDKの削除について

### 各プラットフォーム共通
- いつまでにSDKを削除すればよいか？
  - nendのサービス終了までに、SDKを削除してアプリをアップデートすることを推奨いたします。<br>また、2024年春よりAppStoreの審査方法に変更が予定されております。詳細は<a href="#ioslisk">こちら</a>をご確認ください。
- サービス終了後もnendSDKや、広告に関する実装がそのままの場合どうなってしまうか？
  - nendSDKのファイルがプロジェクト内に残っていてもアプリのビルド、動作への影響はありません。
  - アプリ内にnendSDKが提供しているAPIを使用している場合 広告のロード処理がエラーを返し それ以降の処理は動作しません。
    - アプリ自体に干渉するような処理(バックグラウンドで負荷の高い処理を実行する, 大きいファイルのダウンロードを行う 等)は動作いたしません。
    - 一部に自動リロードを繰り返す処理が存在します。詳細は<a href="#autoreload">こちら</a>をご確認ください。
- SDKをアプリから削除したいがどのようにしたらよいか？
  - 以下のリンク先を参照ください
    - <a href="#ios">iOS版SDKの削除</a>
    - <a href="#android">Android版SDKの削除</a>
    - <a href="#unity">Unityプラグインの削除</a>
    - <a href="#ironsource">ironSourceカスタムアダプターの削除</a>
    - <a href="#ironsourceunity">Unity用ironSourceカスタムアダプターの削除</a>
- SDKを削除する際に注意すべきことはあるか？
  - 依存ライブラリを削除する際、nendSDK以外でも利用しているライブラリを削除してしまった場合、ビルドエラーとなってしまう可能性があります。<br>依存ライブラリを削除する際は、他の実装部分で利用していないことを確認の上削除をお願いします。
- サービス終了以降もSDKが残った場合はどのような影響があるか？
  - 広告のロード処理が実装されている場合、サーバーへのアクセス処理が発生します。
    - サービス終了後はサーバーが停止するため、広告のロードエラーが返却されます。
    - <a name="autoreload"></a>また、バナー広告 及び ネイティブ広告の自動リロード機能を利用している場合、定期的にロード処理が発生します。
- サービス終了になったらSDKからエラーが返ってくるのか？もしくは、リクエストがタイムアウトになるまで待機中とかになるのか？
  - リクエスト用のサーバーが停止するため、即時にSDKからエラーが返却されます。

### <a name="ios">iOS版SDKの削除</a>
#### CocoaPods で追加した場合
- 参考リンク：<a href="https://github.com/fan-ADN/nendSDK-iOS/wiki/SDK%E3%82%92CocoaPods%E3%81%8B%E3%82%89%E8%BF%BD%E5%8A%A0%E3%81%99%E3%82%8B">SDKをCocoaPodsから追加する</a>
- プロジェクトの `Podfile` から、 `pod 'NendSDK_iOS'` の記述を削除します。
- `pod update` を実行し、プロジェクトから nendSDKを削除します。
#### 手動で追加した場合
- 参考リンク：<a href="https://github.com/fan-ADN/nendSDK-iOS/wiki/SDK%E3%82%92%E6%89%8B%E5%8B%95%E3%81%A7%E8%BF%BD%E5%8A%A0%E3%81%99%E3%82%8B">SDKを手動で追加する</a>
- Xcode のプロジェクトナビゲーターから `NendAd.xcframework` と `NendAdResource.bundle` を削除します。
#### <a name="skadnetwork">SKAdNetworkの設定を削除する(CocoaPods, 手動 共通)</a>
`Info.plist` から、nendの`SKAdNetworkIdentifier`を削除します。
- `Info.plist` を開いて`SKAdNetworkItems` を展開します。
- Value に `eh6m2bh4zr.skadnetwork` が設定された `SKAdNetworkIdentifier` を削除します。

`SKAdNetworkItems` 全体 または Valueに `eh6m2bh4zr.skadnetwork` 以外の`SKAdNetworkIdentifier` を削除した場合、他社アドネットワークの広告の効果測定に影響が出る恐れがありますのでご注意ください。

#### <a name="ioslisk">nendSDKが残っていた場合のリスクについて</a>
2024年春より、サードパーティSDKにプライバシーマニフェストファイルが要求されます。
nendSDKでは、プライバシーマニフェストファイルを提供する予定はありません。
そのため、2024年春以降にアプリをAppStoreへ申請する際に受け付けられない可能性があります。
詳細は Appleの公式ドキュメント <a href="https://developer.apple.com/documentation/bundleresources/privacy_manifest_files">Privacy manifest files</a>をご覧ください。

### <a name="android">Android版SDKの削除</a>
参考リンク：<a href="https://github.com/fan-ADN/nendSDK-Android/wiki/SDK%E3%81%AE%E7%B5%84%E3%81%BF%E8%BE%BC%E3%81%BF%E6%96%B9%E6%B3%95">SDKの組み込み方法</a>
#### Gradleで追加した場合
- `settings.gradle` の `dependencyResolutionManagement` から `maven` リポジトリの情報を削除します。
  - repositories - maven から url 'https://fan-adn.github.io/nendSDK-Android-lib/library' を削除します。
- `build.gradle` の `dependencies` から `implementation 'net.nend.android:nend-sdk:x.x.x'` の記述を削除します。
#### aarファイルで追加した場合
- サブプロジェクト配下のlibsディレクトリから`nendSDK-x.x.x.aar`を削除します。
- 必要に応じて dependencies から依存性のあるライブラリを を削除します。
#### Proguardの設定を行なっている場合
- 参考リンク：<a href="https://github.com/fan-ADN/nendSDK-Android/wiki/Proguard-%E3%81%AE%E8%A8%AD%E5%AE%9A">Proguard の設定</a>
- Proguardの設定を行なっている場合は、設定の削除をお願いします。

### <a name="unity">Unityプラグインの削除</a>
- 参考リンク：<a href="https://github.com/fan-ADN/nendSDK-Unity/wiki/Unity%E3%83%91%E3%83%83%E3%82%B1%E3%83%BC%E3%82%B8%E3%81%AE%E3%82%A4%E3%83%B3%E3%83%9D%E3%83%BC%E3%83%88"> Unityパッケージのインポート</a>
- プロジェクトの `Assets` 配下にある `NendAd` を削除します。
##### SKAdNetworkの設定を削除する (iOSのみ)
iOS版SDKの<a href="#skadnetwork">SKAdNetworkの設定を削除する(CocoaPods, 手動 共通)</a>の手順に従い、SKAdNetworkの設定を削除します。

### <a name="ironsource">ironSourceカスタムアダプターの削除</a>
#### iOS
##### CocoaPods で追加した場合
- 参考リンク：<a href="https://github.com/fan-ADN/nendSDK-iOS-ironSource-CustomAdapter/wiki/%E5%B0%8E%E5%85%A5%E6%96%B9%E6%B3%95#cocoapods">CocoaPodsから追加する</a>
- プロジェクトの `Podfile` から `pod 'IronSourceNendCustomAdapter'` の記述を削除します。
- `pod update` を実行し、プロジェクトから ironSourceカスタムアダプターを削除します。
##### 手動で追加した場合
- 参考リンク：<a href="https://github.com/fan-ADN/nendSDK-iOS-ironSource-CustomAdapter/wiki/%E5%B0%8E%E5%85%A5%E6%96%B9%E6%B3%95#%E6%89%8B%E5%8B%95%E3%81%A7%E8%BF%BD%E5%8A%A0%E3%81%99%E3%82%8B">手動で追加する</a>
- Xcode のプロジェクトナビゲーターから `ISNendCustomAdapter` を削除します。
- nendSDKを手動で追加している場合は、追加でXcode のプロジェクトナビゲーターから `NendAd.xcframework` と `NendAdResource.bundle` を削除します。
##### SKAdNetworkの設定を削除する
iOS版SDKの<a href="#skadnetwork">SKAdNetworkの設定を削除する(CocoaPods, 手動 共通)</a>の手順に従い、SKAdNetworkの設定を削除します。
#### Android
##### Gradleで追加した場合
- 参考リンク：<a href="https://github.com/fan-ADN/nendSDK-Android-ironSource-CustomAdapter/wiki/%E5%B0%8E%E5%85%A5%E6%96%B9%E6%B3%95#gradle%E3%81%A7%E8%BF%BD%E5%8A%A0%E3%81%99%E3%82%8B">Gradleで追加する</a>
- `settings.gradle` の `dependencyResolutionManagement` から `maven` リポジトリの情報を削除します。
  - repositories - maven から url 'https://fan-adn.github.io/nendSDK-Android-lib/library' を削除します。
- `build.gradle` の `dependencies` から `implementation 'net.nend.android:nend-custom-event-ironsource:x.x.x'` の記述を削除します。
##### jarファイルで追加した場合
- 参考リンク：<a href="https://github.com/fan-ADN/nendSDK-Android-ironSource-CustomAdapter/wiki/%E5%B0%8E%E5%85%A5%E6%96%B9%E6%B3%95#%E3%82%AB%E3%82%B9%E3%82%BF%E3%83%A0%E3%82%A2%E3%83%80%E3%83%97%E3%82%BF%E3%83%BC%E3%82%92jar%E3%83%95%E3%82%A1%E3%82%A4%E3%83%AB%E3%81%A7%E8%BF%BD%E5%8A%A0%E3%81%99%E3%82%8B"> カスタムアダプターをjarファイルで追加する</a>
- サブプロジェクト配下のlibsディレクトリから`nendIronSourceCustomEvent-x.x.x.x.jar `を削除します。

### <a name="ironsourceunity">Unity用ironSourceカスタムアダプターの削除</a>
- 参考リンク：<a href="https://github.com/fan-ADN/nendSDK-ironSource-Unity-CustomAdapter-XML/blob/main/README.md#add-nend-custom-adapter">Add nend custom adapter</a>
- プロジェクトの `Assets/Editor`配下にある `ISnendCustomAdapterDependencies.xml ` を削除します。
##### SKAdNetworkの設定を削除する (iOSのみ)
iOS版SDKの<a href="#skadnetwork">SKAdNetworkの設定を削除する(CocoaPods, 手動 共通)</a>の手順に従い、SKAdNetworkの設定を削除します。

----

# nendSDK for iOS

![logo](https://user-images.githubusercontent.com/9563381/31269103-17daebce-aaba-11e7-9899-742435c4ef20.png)

## Overview

iOS用nendSDKのリリースリポジトリです。

## Download

[リリースタブ](https://github.com/fan-ADN/nendSDK-iOS-pub/releases)よりダウンロードしてください。

## Supports

* [document](https://github.com/fan-ADN/nendSDK-iOS/wiki)
* [sample](https://github.com/fan-ADN/nendSDK-iOS)

## License
Copyright (C) FAN Communications, Inc.
