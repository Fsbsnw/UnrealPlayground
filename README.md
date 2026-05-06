# UnrealPlayground
기능 테스트 용도

<h3>Data</h3>
<details>
  <summary>아이템 구조</summary>

  [<ItemStructs.h>](Source/Lost/Public/Data/ItemStructs.h) 

  * FItemBase(ItemName : 기본키 + 외래키 역할)
  <img width="700" height="138" alt="image" src="https://github.com/user-attachments/assets/efc41f88-e9d9-4231-9371-6b35de89edef" /><br>

  * FItemCraftData
  <img width="700" height="60" alt="image" src="https://github.com/user-attachments/assets/9876aa19-4ca4-4db9-b081-9dbea6f66b2f" /><br>

</details>

<h3>Components</h3>
<details>
  <summary>인벤토리 컴포넌트</summary>

  [<InventoryComponent.cpp>](Source/Lost/Private/Components/InventoryComponent.cpp)

  <스택 제한 및 아이템 추가 기능>

  <img width="300" height="390" alt="image" src="https://github.com/user-attachments/assets/6d62e17b-e6e8-431d-abd4-88714c8bd8fa" /><br>

  <img width="885" height="745" alt="image" src="https://github.com/user-attachments/assets/2e763d04-e876-496f-bd47-5419bd109984" />

  
</details>

<details>
  <summary>제작 컴포넌트</summary>

  [<CraftingSystem.cpp>](Source/Lost/Private/GameInstance/Subsystem/CraftingSystem.cpp)

  <img width="400" height="225" alt="CraftingGIF" src="https://github.com/user-attachments/assets/f2504cd0-5108-40f0-ab47-f86bb41d9504" /><br>

  * CraftingComponent -> CraftingSystem 호출

  <img width="815" height="305" alt="image" src="https://github.com/user-attachments/assets/1f48401b-e72f-42b5-abd7-f4128e5ded34" /><br>

  <img width="1094" height="571" alt="image" src="https://github.com/user-attachments/assets/28a82cc6-22b9-4ed8-bb82-b2295a13588c" /><br>


  * Crafting Component는 자신이 담당할 제작 아이템 레시피만 소유
  * Crafting System은 전체 제작 아이템 레시피 참고, 재료 아이템 확인 및 제작 아이템 추가

</details>

<h3>Widget</h3>
<details>
  <summary>위젯 구조</summary>

  [<LostUserWidget.cpp>](Source/Lost/Private/UI/Widget/LostUserWidget.cpp)

  [<UIManagerSubsystem.cpp>](Source/Lost/Private/UI/Subsystem/UIManagerSubsystem.cpp)

  * 부모 위젯 닫히면 자식들도 같이 닫히는 구조(캐싱 정책에 따라 Collapsed 결정)

  <img width="431" height="483" alt="image" src="https://github.com/user-attachments/assets/622ccff7-dfc1-4b5a-a005-ab4e2f6b70b5" /><br>

  <img width="599" height="678" alt="image" src="https://github.com/user-attachments/assets/41d59425-5a41-4a55-bb07-c0743301f01f" /><br>


</details>
