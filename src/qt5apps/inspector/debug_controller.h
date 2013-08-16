#ifndef MARSYASQT_INSPECTOR_DEBUG_CONTROLLER_INCLUDED
#define MARSYASQT_INSPECTOR_DEBUG_CONTROLLER_INCLUDED

#include <QObject>

#include <marsyas/core/MarSystem.h>
#include <marsyas/core/realvec.h>
#include <marsyas/debug/file_io.h>
#include <marsyas/debug/recorder.h>
#include <marsyas/debug/debugger.h>

class DebugController : public QObject
{
  Q_OBJECT
public:
  DebugController( QObject * parent = 0 );
  void setSystem( Marsyas::MarSystem * system );
  bool setRecording( const QString & fileName );
  bool endOfRecording()
  {
    return m_reader ? m_reader->eof() : true;
  }
  const Marsyas::Debug::BugReport & report() const { return m_report; }
  const Marsyas::realvec *currentValue( const QString & path ) const;

public slots:
  void tick();
  void rewind();

signals:
  void ticked();
  void recordingChanged(const QString & filename);

private:
  Marsyas::MarSystem * m_system;
  Marsyas::Debug::FileReader *m_reader;
  Marsyas::Debug::Recorder *m_recorder;
  Marsyas::Debug::BugReport m_report;
};

#endif // MARSYASQT_INSPECTOR_DEBUG_CONTROLLER_INCLUDED