#include "workingabouttostartstate.h"
#include "src/network/clientsession.h"

WorkingAboutToStartState::WorkingAboutToStartState(ClientSession *parent) : AbstractState(parent)
{

}

WorkingAboutToStartState::~WorkingAboutToStartState()
{
}

void WorkingAboutToStartState::ProcessUnable(const QStringList &args)
{
    if (args.size() > 0 && args.first() == _client->GetId().toString())
        _client->SetCurrentStateAfterError(UNABLE_TO_CALCULATE);
}

void WorkingAboutToStartState::ProcessWorking(const QStringList &args)
{
    if (args.size() > 0 && args.first() == _client->GetId().toString())
        _client->SetCurrentStateAfterSuccess();
}