# Udemy-Unreal-2026-June

Udemy 언리얼 엔진 강의 실습 저장소입니다. 챕터별로 별도의 언리얼 프로젝트 폴더를 포함합니다.

- **엔진 버전**: Unreal Engine 5.2
- **프로젝트 목록**: `Chapter2/`, `Chapter3/`, `Chapter4/`, `SimpleShooter/`

---

## ⚠️ 클론 후 필수 작업: 외부 에셋 복원

이 저장소는 **GitHub LFS 용량 관리를 위해 외부 에셋팩(강의 제공/마켓플레이스/엔진 기본 콘텐츠)을 git에 포함하지 않습니다.**
클론 직후 상태로 프로젝트를 열면 에셋이 없어 깨져 보이므로, 반드시 아래 절차를 먼저 진행하세요.

### 1. 저장소 클론

```bash
git clone git@github.com:Chillbok/Udemy-Unreal-2026-June.git
cd Udemy-Unreal-2026-June
```

### 2. 에셋 아카이브 다운로드

아래 구글 드라이브 링크에서 에셋 아카이브(zip)를 다운로드합니다 (전체 약 7GB):

> **에셋 다운로드**: [여기에 구글 드라이브 링크 삽입]

### 3. 저장소 루트에 압축 해제

다운로드한 zip을 **저장소 루트(이 README가 있는 위치)에 압축 해제**합니다.
압축 파일 안의 폴더 구조(`Chapter2/Content/...`, `SimpleShooter/Content/...` 등)가 그대로 올바른 위치에 덮어쓰기되도록 풀면 됩니다.

macOS 예시:

```bash
unzip ~/Downloads/asset-packs.zip -d .
```

### 4. 복원 확인

아래 표의 모든 폴더가 존재하면 준비 완료입니다. 이 폴더들은 `.gitignore` 처리되어 있어 git 변경 사항에 표시되지 않는 것이 정상입니다.

| 프로젝트 | 필요한 에셋 폴더 | 크기 |
|---|---|---|
| **Chapter2** | `Chapter2/Content/StarterContent/` | 613MB |
| | `Chapter2/Content/IndustryPropsPack6/` | 182MB |
| **Chapter3** | `Chapter3/Content/LearningKit_Games/` | 681MB |
| | `Chapter3/Content/SCK_Casual01/` | 201MB |
| | `Chapter3/Content/Hour_of_Code/` | 77MB |
| | `Chapter3/Content/LearningKit_Robots/` | 57MB |
| | `Chapter3/Content/BlockGame/` | 27MB |
| **Chapter4** | `Chapter4/Content/MedievalDungeon/` | 2.1GB |
| | `Chapter4/Content/FPWeapon/` | 35MB |
| | `Chapter4/Content/FirstPersonArms/` | 35MB |
| | `Chapter4/Content/FirstPerson/` | 1MB |
| | `Chapter4/Content/LevelPrototyping/` | 1MB |
| **SimpleShooter** | `SimpleShooter/Content/AssetPacks/` | 3.2GB |

### 5. 프로젝트 열기

각 폴더의 `.uproject` 파일을 열면 됩니다. C++ 프로젝트(`Chapter3`, `Chapter4`, `SimpleShooter`)는 첫 실행 시 모듈 빌드 여부를 묻는 창이 나오면 **Yes**를 선택하세요 (Xcode가 필요합니다).

---

## 참고: git 커밋 정책

- 직접 만든 것(소스 코드, `BP_*.uasset`, `*.umap`, Config 등)만 커밋합니다.
- 위 표에 있는 외부 에셋팩 폴더에 새 파일을 추가해도 git에 추적되지 않습니다.
- **⚠️ 직접 만든 에셋은 반드시 무시되는 폴더 "밖"에 두세요.** 예를 들어 `Content/AssetPacks/` 안에 내 블루프린트를 만들면 git에 커밋되지 않습니다. `Content/` 루트나 `Content/MyBlueprints/` 같은 별도 폴더에 만드는 것을 권장합니다.
- 새로운 외부 에셋팩을 프로젝트에 추가한 경우, `.gitignore`의 "외부 에셋팩" 섹션에 경로를 추가해 주세요.
