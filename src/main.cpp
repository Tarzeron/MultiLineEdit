#include <Urho3D/Engine/Application.h>
#include <Urho3D/UI/MultiLineEdit.h>
#include <Urho3D/Resource/XMLFile.h>
#include <Urho3D/UI/UI.h>
#include <Urho3D/Input/Input.h>
#include <Urho3D/Resource/ResourceCache.h>

using namespace Urho3D;

class MyApp: public Application
{
public:
    MyApp(Context *context)
        : Application(context)
    {
    }

    virtual void Setup()
    {
        engineParameters_["FullScreen"] = false;
        engineParameters_["WindowWidth"] = 600;
        engineParameters_["WindowHeight"] = 600;
        engineParameters_["WindowResizable"] = false;
        GetSubsystem<Input>()->SetMouseVisible(true);
        GetSubsystem<Input>()->SetMouseGrabbed(false);
    }

    virtual void Start()
    {
        XMLFile *style = GetSubsystem<ResourceCache>()->GetResource<XMLFile>("UI/DefaultStyle.xml");
        GetSubsystem<UI>()->SetUseSystemClipboard(true);

        MultiLineEdit *multiLineEdit = new MultiLineEdit(GetContext());
        multiLineEdit->SetStyle("MultiLineEdit", style);
        GetSubsystem<UI>()->GetRoot()->AddChild(multiLineEdit);
        multiLineEdit->SetPosition(50, 50);
        multiLineEdit->SetWidth(500);
        multiLineEdit->SetHeight(500);
        multiLineEdit->SetDragDropMode(DragAndDropMode::DD_SOURCE_AND_TARGET);
        multiLineEdit->SetText("Text\n123\n123");
    }
};

URHO3D_DEFINE_APPLICATION_MAIN(MyApp)
